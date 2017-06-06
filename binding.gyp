{
  "targets": [
    {
      "target_name": "accumulation",
      "sources": [ "accumulation.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}