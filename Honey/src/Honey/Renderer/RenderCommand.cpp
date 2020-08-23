#include "hnpch.h"
#include "Honey/Renderer/RenderCommand.h"

namespace Honey {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}