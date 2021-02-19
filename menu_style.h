#pragma once

#include "imgui/imgui.h"
#include "menu.h"


void ApplyStyle()
{
	//==================================================
	//Below here is just to render our mouse cursor so it doesn't go behind the menu etc.

	ImGui::GetMouseCursor();
	ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
	ImGui::GetIO().WantCaptureMouse = Menu::IsMenuOpen;
	ImGui::GetIO().MouseDrawCursor = Menu::IsMenuOpen;

	auto& style = ImGui::GetStyle();

	style.WindowMinSize = ImVec2(900, 540); // This sets the minimum window size

	style.FrameBorderSize					= 0;
	style.WindowRounding				    = 0;
	style.TabRounding						= 0;
	style.ScrollbarRounding					= 0;
	style.FramePadding = ImVec2(8, 6);
	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);

	style.Colors[ImGuiCol_TitleBg]		     = ImColor(227, 0, 40, 255);			// The top bar color
	style.Colors[ImGuiCol_TitleBgActive]	 = ImColor(227, 0, 40, 255);			// When you press in the imgui menu
	style.Colors[ImGuiCol_TitleBgCollapsed]  = ImColor(15, 15, 15, 50);		        // When the title is collapsed

	style.Colors[ImGuiCol_WindowBg]			 = ImColor(12,12,12, 255);				// Window Background

	style.Colors[ImGuiCol_Button]			 = ImColor(24, 25, 24, 255);			// button color
	style.Colors[ImGuiCol_ButtonActive]		 = ImColor(54, 53, 55);	        // button color when pressed
	style.Colors[ImGuiCol_ButtonHovered]	 = ImColor(54, 53, 55);		    // button when hovered

	style.Colors[ImGuiCol_CheckMark]		 = ImColor(255, 255, 255, 255);			//check mark color

	style.Colors[ImGuiCol_FrameBg]	         = ImColor(36, 37, 36, 255);
	style.Colors[ImGuiCol_FrameBgActive]	 = ImColor(36, 37, 36, 255);
	style.Colors[ImGuiCol_FrameBgHovered]	 = ImColor(36, 37, 36, 255);
	
	style.Colors[ImGuiCol_Header]			 = ImColor(24, 24, 24, 255);			// for collapsing headers , etc
	style.Colors[ImGuiCol_HeaderActive]		 = ImColor(54, 53, 55);
	style.Colors[ImGuiCol_HeaderHovered]	 = ImColor(24, 24, 24, 100);

	style.Colors[ImGuiCol_ResizeGrip]		 = ImColor(51, 49, 50, 255);		    // the resize grip thing bottom right
	style.Colors[ImGuiCol_ResizeGripActive]  = ImColor(54, 53, 55);			// when you hold it / active
	style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(51, 49, 50, 255);			// when you hover over it

	style.Colors[ImGuiCol_SliderGrab]		 = ImColor(249, 79, 49,255);
	style.Colors[ImGuiCol_SliderGrabActive]  = ImColor(249, 79, 49,255);

	style.Colors[ImGuiCol_Border]			 = ImColor(54, 54, 54);
	style.Colors[ImGuiCol_Separator]		 = ImColor(54, 54, 54);
	style.Colors[ImGuiCol_SeparatorActive]   = ImColor(54, 54, 54);
	style.Colors[ImGuiCol_SeparatorHovered]  = ImColor(54, 54, 54);

}