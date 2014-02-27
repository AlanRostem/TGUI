/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2014 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_GRID_HPP
#define TGUI_GRID_HPP


#include <TGUI/Container.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API Grid : public Container
    {
      public:

        typedef SharedWidgetPtr<Grid> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief The layout of the widget.
        ///
        /// Where in the cell is the widget located?
        /// The widget is centered by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct Layout
        {
            /// \brief The layout of the widget.
            enum Layouts
            {
                UpperLeft,   ///< Draw the widget in the upper left corner of the cell
                Up,          ///< Draw the widget at the upper side of the cell (horizontally centered)
                UpperRight,  ///< Draw the widget in the upper right corner of the cell
                Right,       ///< Draw the widget at the right side of the cell (vertically centered)
                BottomRight, ///< Draw the widget in the bottom right corner of the cell
                Bottom,      ///< Draw the widget at the bottom of the cell (horizontally centered)
                BottomLeft,  ///< Draw the widget in the bottom left corner of the cell
                Left,        ///< Draw the widget at the left side of the cell (vertically centered)
                Center       ///< Center the widget in the cell
            };
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Grid();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Grid(const Grid& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Grid();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Grid& operator= (const Grid& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Grid* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the grid.
        ///
        /// \param width   Width of the grid
        /// \param height  Height of the grid
        ///
        /// Widgets in the grid will be repositionned to fill in the best way the available space of the grid.
        /// If the size is too small to have all Widgets correctly placed, the size will be ignored and the grid auto-sized until
        /// some Widgets are removed of the grid and the size was become valid again.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the grid.
        ///
        /// \return Size of the grid
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::Vector2f getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes a single widget that was added to the container.
        ///
        /// \param widget  Pointer to the widget to remove
        ///
        /// \see remove(sf::String)
        ///
        /// Usage example:
        /// \code
        /// tgui::Picture::Ptr pic(grid, "picName");
        /// tgui::Picture::Ptr pic2(grid, "picName2");
        /// grid.remove(pic);
        /// grid.remove(grid.get("picName2"));
        /// \endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void remove(const Widget::Ptr& widget);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes a single widget that was added to the container.
        ///
        /// \param widget  Pointer to the widget to remove
        ///
        /// This function is provided for internal use.
        /// The other remove function will probably be easier to use, but in the end they do exactly the same.
        ///
        /// \see remove(Widget::Ptr)
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void remove(Widget* widget);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes all widgets that were added to the container.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void removeAllWidgets();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Add a widget to the grid.
        ///
        /// \param widget  Pointer to a fully created widget that will be added to the grid
        /// \param row     The row in which the widget should be placed
        /// \param column  The column in which the widget should be placed
        /// \param borders  Distance from the grid square to the widget (left, top, right, bottom)
        /// \param layout   Where the widget is located in the square
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addWidget(const Widget::Ptr& widget,
                       unsigned int       row,
                       unsigned int       column,
                       const Borders&     borders = Borders(0, 0, 0, 0),
                       Layout::Layouts    layout  = Layout::Center);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the widget in a specific square of the grid.
        ///
        /// \param row     The row that the widget is in
        /// \param column  The column that the widget is in
        ///
        /// \return The widget inside the given square, or nullptr when the square doesn't contain a widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget::Ptr getWidget(unsigned int row, unsigned int column);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Updates the position and size of the widget.
        ///
        /// Once a widget has been added to the grid, you will have to call this function every time you change the size of the widget.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateWidgets();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes borders of a given widget.
        ///
        /// \param widget  The widget to which borders should be added
        /// \param borders The new borders around the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void changeWidgetBorders(const Widget::Ptr& widget, const Borders& borders = Borders(0, 0, 0, 0));


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the layout of a given widget.
        ///
        /// \param widget  The widget for which the layout should be changed
        /// \param layout  The new layout
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void changeWidgetLayout(const Widget::Ptr& widget, Layout::Layouts layout = Layout::Center);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnWidget(float x, float y);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Returns the minimum size required by the grid to display correctly all widgets.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::Vector2f getMinSize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Reposition all the widgets.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updatePositionsOfAllWidgets();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Defines specific triggers to Grid.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum GridCallbacks
        {
            AllGridCallbacks = WidgetCallbacksCount - 1, ///< All Callbacks defined in Grid and its base classes
            GridCallbacksCount = WidgetCallbacksCount
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        std::vector< std::vector<Widget::Ptr> >     m_gridWidgets;
        std::vector< std::vector<Borders> >         m_objBorders;
        std::vector< std::vector<Layout::Layouts> > m_objLayout;

        std::vector<unsigned int> m_rowHeight;
        std::vector<unsigned int> m_columnWidth;

        sf::Vector2f m_size; // Real (optimal) size of the grid
        sf::Vector2f m_intendedSize; // Intended size that the grid should have if it is possible


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_GRID_HPP
