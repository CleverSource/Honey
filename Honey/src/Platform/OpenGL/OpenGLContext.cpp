#include "hnpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Honey {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HN_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		HN_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HN_CORE_ASSERT(status, "Failed to initialize Glad!");

		HN_CORE_INFO("OpenGL Info:");
		HN_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		HN_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		HN_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		HN_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Honey requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		HN_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
