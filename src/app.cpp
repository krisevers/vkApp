#include "app.h"

#include <chrono>
#include <thread>

App::App()
{
}

void App::run()
{
    init();
    loop();
    cleanup();
}

void App::init()
{
    if (m_window.init(WIDTH, HEIGHT, "vkApp") != GLFW_TRUE) {
        throw std::runtime_error("creating window failed!");
    }
    if (m_context.init(m_window.get()) != VK_SUCCESS ) {
        throw std::runtime_error("creating context failed!");
    }
    if (m_renderer.init(m_context, m_window.get()) != VK_SUCCESS) {
        throw std::runtime_error("creating renderer failed!");
    }

}

void App::cleanup()
{
    m_renderer.cleanup(m_context);
    m_context.cleanup();
    m_window.cleanup();
}

void App::loop()
{
    while (!glfwWindowShouldClose(m_window.get()))
    {
        glfwPollEvents();
        if (glfwGetKey(m_window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(m_window.get(), GLFW_TRUE);
        }



        
        /*
        goal architecture
        m_window.update();                  << check for resizing and closing
        m_control.update(m_window);         << handles user input
        m_events.update(m_control);         << handles state updates (editing & adding entities and components)
        m_simulation.update(m_events);      << update world simulation (run systems on components)
        m_renderer.update(m_simulation);    << update compute buffers & render graphics

        if (editorOn) {
            editor.update();                << handles editor state updates
        }
        */
    }
}


/*

// pseudocode
update()
{
    // logic (input & events)
    vkWaitForFences();
    if (editorOn) {
        editor.update();
    }
    >> eventQueue? << 
    updateLogic();
    VkResetFences();

    // compute
    vkWaitForFences();
    updateBuffers();
    vkResetFences();
    recordComputeCommandBuffer();
    vkQueueSubmit(computeQueue); << semaphores

    // graphics
    vkWaitForFences();
    acquireNextImage();
    >> recreateSwapChain
    vkResetFences();
    recordGraphicsCommandBuffer();
    vkQueueSubmit(graphicsQueue); << semaphores

    vkQueuePresent(presentQueue) << semaphores
    >> recreateSwapChain
}

*/