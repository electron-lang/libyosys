{
  "targets": [{
    "target_name": "libyosys-napi",
    "sources": [
      "libyosys-napi.c"
    ],
    "link_settings": {
      "libraries": [
        "-lyosys",
      ],
      "library_dirs": [
        "../yosys-src",
      ],
    }
  }]
}
