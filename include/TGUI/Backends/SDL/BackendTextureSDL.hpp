/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2020 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_BACKEND_TEXTURE_SDL_HPP
#define TGUI_BACKEND_TEXTURE_SDL_HPP

#include <TGUI/BackendTexture.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SDL_Surface;
typedef unsigned int GLuint;

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Texture implementation that makes use of SDL
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API BackendTextureSDL : public BackendTextureBase
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ~BackendTextureSDL();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the texture from a file
        ///
        /// @param filename  Filename of the image to load
        ///
        /// @return True if the image was loaded successfully, false on failure
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool loadFromFile(const String& filename) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the texture from an array of 32-bits RGBA pixels
        ///
        /// @param size   Width and height of the image to create
        /// @param pixels Pointer to array of size.x*size.y*4 bytes with RGBA pixels, or a nullptr to create an empty texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool loadFromPixelData(Vector2u size, const std::uint8_t* pixels) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the entire image
        /// @return Texture size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2u getSize() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the smooth filter is enabled or not
        ///
        /// @param smooth  True if smoothing should be enabled, false if it should be disabled
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSmooth(bool smooth) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the smooth filter is enabled or not
        ///
        /// @return True if smoothing is enabled, false if it is disabled
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isSmooth() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Checks if a certain pixel is transparent
        ///
        /// @param pos  Coordinate of the pixel
        ///
        /// @return True when the pixel is transparent, false when it is not
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isTransparentPixel(Vector2u pixel) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns a pointer to the internal SDL texture
        /// @return Pointer to internal texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        GLuint getInternalTexture() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Deletes the image and texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void releaseResources();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        SDL_Surface* m_image = nullptr;
        GLuint m_textureId = 0;
    };
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_BACKEND_TEXTURE_SDL_HPP
