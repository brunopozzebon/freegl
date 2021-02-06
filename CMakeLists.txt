cmake_minimum_required(VERSION 3.17)
project(freegl)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        freegl
        main.cpp

        src/utils/imgui/imgui.cpp
        src/utils/imgui/imgui_draw.cpp
        src/utils/imgui/imgui_widgets.cpp
        src/utils/imgui/imgui_demo.cpp
        src/utils/imgui/imstb_rectpack.h
        src/utils/imgui/imgui_tables.cpp
        src/utils/imgui/imstb_truetype.h
        src/utils/imgui/imstb_textedit.h
        src/utils/imgui/imgui_impl_glfw.cpp
        src/utils/imgui/imgui_impl_opengl3.cpp

        src/raw/Window.h
        src/raw/Window.cpp

        src/raw/IndexBuffer.cpp
        src/raw/IndexBuffer.h
        src/raw/VertexBuffer.h
        src/raw/VertexBuffer.cpp
        src/raw/VertexArrayLayout.h
        src/raw/VertexArrayLayout.cpp
        src/raw/VertexArray.h
        src/raw/VertexArray.cpp
        src/raw/Shader.h
        src/raw/Shader.cpp
        src/raw/Renderer.h
        src/raw/Renderer.cpp
        src/raw/Texture.h
        src/raw/Texture.cpp
        src/raw/Interface.h
        src/raw/Interface.cpp

        src/basics/Vertex.h
        src/basics/Vertex.cpp
        src/basics/TextureCoord.h
        src/basics/TextureCoord.cpp
        src/basics/Position.h
        src/basics/Position.cpp
        src/basics/Color.cpp
        src/basics/Color.h

        src/models/Mesh.h
        src/models/Mesh.cpp
        src/models/Plane.cpp
        src/models/Plane.h

        src/camera/OrthographicCamera.h
        src/camera/OrthographicCamera.cpp

        src/compound3dObject/Cube.h
        src/compound3dObject/Cube.cpp
        src/utils/Convertion.h)

target_link_libraries(freegl -lglut -lglfw -lGLEW -lGL -lGLU)