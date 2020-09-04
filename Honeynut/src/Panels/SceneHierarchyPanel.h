#pragma once

#include "Honey/Core/Base.h"
#include "Honey/Core/Log.h"
#include "Honey/Scene/Scene.h"
#include "Honey/Scene/Entity.h"

namespace Honey {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}
