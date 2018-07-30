{
  "targets": [{
    "target_name": "libyosys_napi",
    "sources": [
      "libyosys_napi.c"
    ],
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
