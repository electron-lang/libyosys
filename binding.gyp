{
  "targets": [{
    "target_name": "libyosys_napi",
    "cflags": [ "-fexceptions" ],
    "cflags_cc": [ "-fexceptions" ],
    "sources": [
      "libyosys_napi.cpp"
    ],
    "include_dirs": [
      "<!@(node -p \"require('node-addon-api').include\")",
      "yosys-src"
    ],
    "defines": [ "NAPI_CPP_EXCEPTIONS", "_YOSYS_" ],
    "link_settings": {
      "libraries": [
        "-lyosys",
        "-Wl,-rpath,\$$ORIGIN",
        "-Wl,-z,origin"
      ],
      "library_dirs": [
        "../yosys-src",
      ],
    },
    "copies":
    [
      {
        "destination": "<(module_root_dir)/build/Release",
        "files": ["<(module_root_dir)/yosys-src/libyosys.so"]
      }
    ]
  }]
}
