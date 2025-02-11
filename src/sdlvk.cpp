
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_vulkan.h>

#include <vulkan/vulkan.h>

#include <string>
#include<vector>
#include <iostream>
#include <stdexcept>
#include <cstdlib>


constexpr int WIDTH{ 1920 };
constexpr int HEIGHT{ 1080 };

class HelloTriangleApplication
{
public:
	void run()
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}
private:
	SDL_Window* window{nullptr};
	VkInstance instance;


	void initWindow()
	{
		SDL_Init(SDL_INIT_VIDEO);

		window = SDL_CreateWindow("Vulkan Window", WIDTH, HEIGHT, SDL_WINDOW_VULKAN);
	}

	void createInstance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "HelloTriangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};

		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t sdlExtensionCount = 0;
		const char* const* sdlExtensions;

		sdlExtensions = SDL_Vulkan_GetInstanceExtensions(&sdlExtensionCount);

		createInfo.enabledExtensionCount = sdlExtensionCount;
		createInfo.ppEnabledExtensionNames = sdlExtensions;

		createInfo.enabledLayerCount = 0;
		
		if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create instance!");
		}


		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

		SDL_Log("available extensions:\n");

		for (const auto& extension : extensions)
		{
			SDL_Log("\t%s\n", extension.extensionName);
		}


	}
	void initVulkan()
	{
		createInstance();
	}
	void mainLoop()
	{
		bool quit{ false };

		SDL_Event e;
		SDL_zero(e);

		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_EVENT_QUIT)
				{
					quit = true;
				}
			}

		}

	}
	void cleanup()
	{
		vkDestroyInstance(instance,nullptr);

		SDL_DestroyWindow(window);
		window = nullptr;

		SDL_Quit();
	}

	
};


int main(int argc, char* argv[])
{
	HelloTriangleApplication app;

	try
	{
		app.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}