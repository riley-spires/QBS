#include "../../qbs.h"



int main() {
    int ret = 0;

    const std::string EXTRACTED_RAYLIB_PATH = "raylib-5.5/";

    qbs::Build build("raylib");

    build.set_output_dir("lib");
    build.set_compiler(qbs::Compiler::clang);
    build.set_build_type(qbs::BuildType::lib);

    qbs::Utils::fetch("https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz");
    qbs::Utils::decompress("5.5.tar.gz");

    build.append_flag("D_GLFW_X11"/*,
                      "D_GNU_SOURCE",
                      "DPLATFORM_DESKTOP_GLFW",
                      "DGRAPHICS_API_OPENGL_33"*/);

    build.append_source_dir(EXTRACTED_RAYLIB_PATH + "src", false);
    build.append_include_dir(EXTRACTED_RAYLIB_PATH + "src/external/glfw");

    ret += build.build();

    qbs::Utils::make_dir_if_not_exists("include");

    qbs::Cmd cmd("mv", EXTRACTED_RAYLIB_PATH + "src/ray*.h", "include");

    ret += cmd.run();

    build.clear("main");

    build.append_source_dir("src");
    build.append_include_dir("include");

    build.append_link_dir("lib");
    build.link_file("raylib");

    ret += build.build_and_run();

    return ret;
}
