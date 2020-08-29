#include "hnpch.h"
#include "Entity.h"

namespace Honey {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}