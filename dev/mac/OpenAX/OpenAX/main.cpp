#include "OpenAX.h"
#include "Slider.h"

int main()
{
	ax::App& app(ax::App::GetInstance());

	app.AddMainEntry([&app]() {
		// Main window.
		ax::Window* win = ax::Window::Create(ax::Rect(0, 0, 500, 500));

		win->event.OnPaint = ax::WFunc<ax::GC>([win](ax::GC gc) {
			const ax::Rect rect(win->dimension.GetRect());
			gc.SetColor(ax::Color(1.0));
			gc.DrawRectangle(rect);
		});

		app.AddTopLevel(ax::Window::Ptr(win));
		
		ax::Slider::Info sld_info;
		sld_info.img_path = "";
		sld_info.btn_size = ax::Size(0, 0);
		sld_info.slider_width = 8;
		sld_info.contour_round_radius = 0;
		sld_info.bgColorNormal = ax::Color(0.5);
		sld_info.bgColorHover = ax::Color(0.5);
		sld_info.bgColorClicked = ax::Color(0.5);
		sld_info.sliderColorNormal = ax::Color(255, 0, 0);
		sld_info.sliderColorHover = ax::Color(255, 0, 0);
		sld_info.sliderColorClicked = ax::Color(255, 0, 0);
		sld_info.sliderContourColor = ax::Color(255, 0, 0);
		sld_info.contourColor = ax::Color(0.0);
		sld_info.backSliderColor = ax::Color(0.0);
		sld_info.backSliderContourColor = ax::Color(0.0);
		
		auto constrate_sld
		= ax::shared<ax::Slider>(ax::Rect(ax::Point(100, 100), ax::Size(300, 20)),
								 ax::Slider::Events(), sld_info, ax::Slider::Flags::CLICK_ANYWHERE);
		win->node.Add(constrate_sld);
	});

	app.AddAfterGUILoadFunction(
		[&app]() { app.SetFrameSize(ax::Size(500, 500)); });

	app.MainLoop();

	return 0;
}
