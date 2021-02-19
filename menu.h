#pragma once

#include "font_awesome.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui.h"

#include "default.h"
#include "exec.h"
#include "resources.h"
#include "luamenus.h"
#include "config.h"

#include "gui.h"

ID3D11ShaderResourceView* logo = NULL;

namespace Menu
{
	int logoWidth = 18;
	int logoHeight = 18;
	static int Tab = 0;
	bool IsMenuOpen = true;

	void Render()
	{
		//redENGINE Remade : by xo1337 
		ImGui::Begin("redENGINE", NULL, ImGuiWindowFlags_NoScrollbar); 
		ImGui::Columns(2, "##maincolumn", true);
		ImGui::SetColumnOffset(1, 225);

		ImGui::SetCursorPosX(74);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 9);
		ImGui::Image((void*)logo, ImVec2(76, 87)); 
		ImGui::NewLine();

		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		Gui::Seperator("##main_seperator_1", 225, 1);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		if (ImGui::Button(ICON_FA_CODE" Executor", ImVec2(225, 46)))
		{
			Tab = 1;
		}
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		Gui::Seperator("##main_seperator_2", 225, 1);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		if (ImGui::Button(ICON_FA_DOWNLOAD" Resources", ImVec2(225, 46)))
		{
			Tab = 2;
		}
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		Gui::Seperator("##main_seperator_3", 225, 1);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3); //+ goes down , - goes up
		ImGui::SetCursorPosX(0);
		if (ImGui::Button(ICON_FA_BOOK" Menus", ImVec2(225, 46)))
		{
			Tab = 3;
		}
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		Gui::Seperator("##main_seperator_4", 225, 1);

		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::SetCursorPosX(0);
		if (ImGui::Button(ICON_FA_COGS" Config", ImVec2(225, 46)))
		{
			Tab = 4;
		}
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 4);
		ImGui::SetCursorPosX(0);
		Gui::Seperator("##main_seperator_5", 225, 1);
		
		ImGui::SetCursorPosY(380);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 25);
		ImGui::Text("Licensed to #4278");
		ImGui::SetCursorPosY(399);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 18);
		ImGui::Text("Build Date: Feb 10 2021");

		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 10); //Same here
		ImGui::Text(""); //Makes sure that the column goes the whole gui height, so don't remove :)

		ImGui::NextColumn();

		if (Tab == 0) 
		{
			Default::Render();
		}
		if (Tab == 1)
		{
			Executor::Render();
		}
		else if (Tab == 2)
		{
			Resources::Render();
		}
		else if (Tab == 3)
		{
			Menus::Render();
		}
		else if (Tab == 4)
		{
			Config::Render();
		}

		ImGui::End();
	}
		
}