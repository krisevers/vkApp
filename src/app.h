#ifndef APP_H
#define APP_H

#include "core/core.h"

#include <memory>
#include <chrono>
#include <thread>

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
        Window m_window;
        Context m_context;
        Renderer m_renderer;

        std::unique_ptr<VkDescriptorPool> descriptorPool{};

        // std::queue<Pipeline> pipelines;
        // std::queue<Command> commands;



        // void createVertices();
        // void createUniformBuffer();
        // void createPipelines();
        // void createCommandBuffer();

        bool editorOn = true;
        float m_elapsedTime = 0.0f;

};

#endif // APP_H