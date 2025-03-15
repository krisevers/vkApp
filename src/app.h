#ifndef APP_H
#define APP_H

#include "core/core.h"

class App
{
    public:
        App();
        void run();

    protected:
        void init();
        void cleanup();
        void loop();
        // void draw() final;
        // void update(float timeElapsed) final;
        // void onResize(int width, int height) final;

    private:
        GLFWwindow* window;
        VulkanContext m_context;

        Renderer m_renderer;

        // void createVertices();
        // void createUniformBuffer();
        // void createPipelines();
        // void createCommandBuffer();

        float m_elapsedTime = 0.0f;

};

#endif // APP_H