#include "hnpch.h"
#include "ScriptGlue.h"
#include "ScriptEngine.h"

#include "Honey/Core/UUID.h"
#include "Honey/Core/KeyCodes.h"
#include "Honey/Core/Input.h"

#include "Honey/Scene/Scene.h"
#include "Honey/Scene/Entity.h"

#include "Honey/Physics/Physics2D.h"

#include "mono/metadata/object.h"
#include "mono/metadata/reflection.h"

#include "box2d/b2_body.h"

namespace Honey {

	namespace Utils {

		std::string MonoStringToString(MonoString* string)
		{
			char* cStr = mono_string_to_utf8(string);
			std::string str(cStr);
			mono_free(cStr);
			return str;
		}

	}

	static std::unordered_map<MonoType*, std::function<bool(Entity)>> s_EntityHasComponentFuncs;

#define HN_ADD_INTERNAL_CALL(Name) mono_add_internal_call("Honey.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		std::string str = Utils::MonoStringToString(string);
		std::cout << str << ", " << parameter << std::endl;
	}

	static void NativeLog_Vector(glm::vec3* parameter, glm::vec3* outResult)
	{
		HN_CORE_WARN("Value: {0}", *parameter);
		*outResult = glm::normalize(*parameter);
	}

	static float NativeLog_VectorDot(glm::vec3* parameter)
	{
		HN_CORE_WARN("Value: {0}", *parameter);
		return glm::dot(*parameter, *parameter);
	}

	static MonoObject* GetScriptInstance(UUID entityID)
	{
		return ScriptEngine::GetManagedInstance(entityID);
	}

	static bool Entity_HasComponent(UUID entityID, MonoReflectionType* componentType)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		MonoType* managedType = mono_reflection_type_get_type(componentType);
		HN_CORE_ASSERT(s_EntityHasComponentFuncs.find(managedType) != s_EntityHasComponentFuncs.end());
		return s_EntityHasComponentFuncs.at(managedType)(entity);
	}

	static uint64_t Entity_FindEntityByName(MonoString* name)
	{
		char* nameCStr = mono_string_to_utf8(name);

		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->FindEntityByName(nameCStr);
		mono_free(nameCStr);

		if (!entity)
			return 0;

		return entity.GetUUID();
	}

	static void TransformComponent_GetTranslation(UUID entityID, glm::vec3* outTranslation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		*outTranslation = entity.GetComponent<TransformComponent>().Translation;
	}

	static void TransformComponent_SetTranslation(UUID entityID, glm::vec3* translation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		entity.GetComponent<TransformComponent>().Translation = *translation;
	}

	static void Rigidbody2DComponent_ApplyLinearImpulse(UUID entityID, glm::vec2* impulse, glm::vec2* point, bool wake)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->ApplyLinearImpulse(b2Vec2(impulse->x, impulse->y), b2Vec2(point->x, point->y), wake);
	}

	static void Rigidbody2DComponent_ApplyLinearImpulseToCenter(UUID entityID, glm::vec2* impulse, bool wake)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->ApplyLinearImpulseToCenter(b2Vec2(impulse->x, impulse->y), wake);
	}

	static void Rigidbody2DComponent_GetLinearVelocity(UUID entityID, glm::vec2* outLinearVelocity)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		const b2Vec2& linearVelocity = body->GetLinearVelocity();
		*outLinearVelocity = glm::vec2(linearVelocity.x, linearVelocity.y);
	}

	static Rigidbody2DComponent::BodyType Rigidbody2DComponent_GetType(UUID entityID)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		return Utils::Rigidbody2DTypeFromBox2DBody(body->GetType());
	}

	static void Rigidbody2DComponent_SetType(UUID entityID, Rigidbody2DComponent::BodyType bodyType)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->SetType(Utils::Rigidbody2DTypeToBox2DBody(bodyType));
	}

	static MonoString* TextComponent_GetText(UUID entityID)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		return ScriptEngine::CreateString(tc.TextString.c_str());
	}

	static void TextComponent_SetText(UUID entityID, MonoString* textString)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		tc.TextString = Utils::MonoStringToString(textString);
	}

	static void TextComponent_GetColor(UUID entityID, glm::vec4* color)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		*color = tc.Color;
	}

	static void TextComponent_SetColor(UUID entityID, glm::vec4* color)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		tc.Color = *color;
	}

	static float TextComponent_GetKerning(UUID entityID)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		return tc.Kerning;
	}

	static void TextComponent_SetKerning(UUID entityID, float kerning)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		tc.Kerning = kerning;
	}

	static float TextComponent_GetLineSpacing(UUID entityID)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		return tc.LineSpacing;
	}

	static void TextComponent_SetLineSpacing(UUID entityID, float lineSpacing)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		HN_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		HN_CORE_ASSERT(entity);
		HN_CORE_ASSERT(entity.HasComponent<TextComponent>());

		auto& tc = entity.GetComponent<TextComponent>();
		tc.LineSpacing = lineSpacing;
	}

	static bool Input_IsKeyDown(KeyCode keycode)
	{
		return Input::IsKeyPressed(keycode);
	}

	template<typename... Component>
	static void RegisterComponent()
	{
		([]()
		{
			std::string_view typeName = typeid(Component).name();
			size_t pos = typeName.find_last_of(':');
			std::string_view structName = typeName.substr(pos + 1);
			std::string managedTypename = fmt::format("Honey.{}", structName);

			MonoType* managedType = mono_reflection_type_from_name(managedTypename.data(), ScriptEngine::GetCoreAssemblyImage());
			if (!managedType)
			{
				HN_CORE_ERROR("Could not find component type {}", managedTypename);
				return;
			}
			s_EntityHasComponentFuncs[managedType] = [](Entity entity) { return entity.HasComponent<Component>(); };
		}(), ...);
	}

	template<typename... Component>
	static void RegisterComponent(ComponentGroup<Component...>)
	{
		RegisterComponent<Component...>();
	}

	void ScriptGlue::RegisterComponents()
	{
		s_EntityHasComponentFuncs.clear();
		RegisterComponent(AllComponents{});
	}

	void ScriptGlue::RegisterFunctions()
	{
		HN_ADD_INTERNAL_CALL(NativeLog);
		HN_ADD_INTERNAL_CALL(NativeLog_Vector);
		HN_ADD_INTERNAL_CALL(NativeLog_VectorDot);

		HN_ADD_INTERNAL_CALL(GetScriptInstance);

		HN_ADD_INTERNAL_CALL(Entity_HasComponent);
		HN_ADD_INTERNAL_CALL(Entity_FindEntityByName);

		HN_ADD_INTERNAL_CALL(TransformComponent_GetTranslation);
		HN_ADD_INTERNAL_CALL(TransformComponent_SetTranslation);

		HN_ADD_INTERNAL_CALL(Rigidbody2DComponent_ApplyLinearImpulse);
		HN_ADD_INTERNAL_CALL(Rigidbody2DComponent_ApplyLinearImpulseToCenter);
		HN_ADD_INTERNAL_CALL(Rigidbody2DComponent_GetLinearVelocity);
		HN_ADD_INTERNAL_CALL(Rigidbody2DComponent_GetType);
		HN_ADD_INTERNAL_CALL(Rigidbody2DComponent_SetType);

		HN_ADD_INTERNAL_CALL(TextComponent_GetText);
		HN_ADD_INTERNAL_CALL(TextComponent_SetText);
		HN_ADD_INTERNAL_CALL(TextComponent_GetColor);
		HN_ADD_INTERNAL_CALL(TextComponent_SetColor);
		HN_ADD_INTERNAL_CALL(TextComponent_GetKerning);
		HN_ADD_INTERNAL_CALL(TextComponent_SetKerning);
		HN_ADD_INTERNAL_CALL(TextComponent_GetLineSpacing);
		HN_ADD_INTERNAL_CALL(TextComponent_SetLineSpacing);

		HN_ADD_INTERNAL_CALL(Input_IsKeyDown);
	}

}
