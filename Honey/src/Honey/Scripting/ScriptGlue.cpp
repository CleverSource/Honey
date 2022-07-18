#include "hnpch.h"
#include "ScriptGlue.h"

#include "mono/metadata/object.h"

namespace Honey {

#define HN_ADD_INTERNAL_CALL(Name) mono_add_internal_call("Honey.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		char* cStr = mono_string_to_utf8(string);
		std::string str(cStr);
		mono_free(cStr);
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

	void ScriptGlue::RegisterFunctions()
	{
		HN_ADD_INTERNAL_CALL(NativeLog);
		HN_ADD_INTERNAL_CALL(NativeLog_Vector);
		HN_ADD_INTERNAL_CALL(NativeLog_VectorDot);
	}

}
