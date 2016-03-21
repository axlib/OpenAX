/*
 * Copyright (c) 2015 Alexandre Arsenault.
 *
 * This file is part of axFrameworks.
 *
 * axFrameworks is free or commercial software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 or any later version of the
 * License or use a commercial axFrameworks License.
 *
 * axFrameworks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with axFrameworks. If not, see <http://www.gnu.org/licenses/>.
 *
 * To release a closed-source product which uses axFrameworks, commercial
 * licenses are available, email alx.arsenault@gmail.com for more information.
 */
#ifndef __AX_LABEL__
#define __AX_LABEL__

/// @defgroup Widgets
/// @{

/// @defgroup Label
/// @{

#include "OpenAX.h"

namespace ax {
class Label : public ax::Window::Backbone {
public:
	class Info : public ax::widget::Info {
	public:
		Info();

		Info(const ax::StringPairVector& attributes);

		virtual ax::StringVector GetParamNameList() const;
		virtual std::string GetAttributeValue(const std::string& name);
		virtual void SetAttribute(const ax::StringPair& attribute);
		
		ax::Color normal;
		ax::Color contour;
		ax::Color font_color;
		int font_size;
		std::string font_name;
		ax::Utils::Alignement alignement;
	};

	class Component : public ax::widget::Component {
	public:
		Component(ax::Window* win, Info* info);

		virtual ax::Xml::Node Save(ax::Xml& xml, ax::Xml::Node& node);
		virtual ax::StringPairVector GetBuilderAttributes();
		
		virtual void SetBuilderAttributes(const ax::StringPairVector& attributes);
		virtual void SetInfo(const ax::StringPairVector& attributes);
		virtual void ReloadInfo();
	};

	class Builder : public ax::widget::Builder {
	public:
		Builder();

		virtual std::shared_ptr<ax::Window::Backbone> Create(
			const ax::Point& pos, const std::string& file_path);

		std::shared_ptr<ax::Window::Backbone> Create(ax::Xml::Node& node);
	};

	Label(const ax::Rect& rect, const Label::Info& info,
		const std::string& label);

	void SetLabel(const std::string& label);
	
	std::string GetLabel() const
	{
		return _label;
	}

private:
	std::string _label;
	std::unique_ptr<ax::Font> _font;

	// Events.
	void OnPaint(ax::GC gc);
};
}

/// @}
/// @}
#endif // __AX_LABEL__.