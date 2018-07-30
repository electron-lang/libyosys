{
  "targets": [{
    "target_name": "libyosys_napi",
    "cflags!": [ "-fno-exceptions" ],
    "cflags_cc!": [ "-fno-exceptions" ],
    "sources": [
      "libyosys_napi.cpp"
    ],
    "include_dirs": [
      "<!@(node -p \"require('node-addon-api').include\")",
      "yosys-src"
    ],
    "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS", "_YOSYS_" ],
    "link_settings": {
      "libraries": [
        "-lyosys",
        "-Wl,-rpath,\$$ORIGIN",
        "-Wl,-z,origin"
      ],
      "library_dirs": [
        "../yosys-src",
      ],
    }
  }]
}
