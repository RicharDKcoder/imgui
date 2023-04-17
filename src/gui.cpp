#include "gui.h"
#include "imgui.h"

#include <iostream>
#include "httplib.h"

MainUI::MainUI()
{
}

MainUI::~MainUI()
{
}

void MainUI::Draw()
{
    // ImGui::ShowDemoWindow();

    ImGui::Begin("button1");
    if (ImGui::Button("按钮1"))
    {
        std::cout << "click 1" << std::endl;
    }
    ImGui::End();

    ImGui::Begin("button2");
    if (ImGui::Button("button2"))
    {
        // HTTP
        httplib::Client cli = httplib::Client("http://baidu.com");
        httplib::Result res = cli.Get("/");
        std::cout << res << std::endl;
        if (res)
        {
            std::cout << res->status << std::endl;
            std::cout << res->body << std::endl;
        }
    }
    ImGui::End();
}