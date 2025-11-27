{
	"targets": [
		{
			"target_name": "pcsclite",
			"sources": [
				"src/addon.cpp",
				"src/pcsclite.cpp",
				"src/cardreader.cpp",
				"src/constants.cpp"
			],
			"cflags": [
				"-Wall",
				"-Wextra",
				"-Wno-unused-parameter",
				"-fPIC",
				"-fno-strict-aliasing",
				"-fno-exceptions",
				"-pedantic"
			],
			"conditions": [
				[
					"OS=='linux'",
					{
						"include_dirs": [
							"/usr/include/PCSC",
							"<!(node -e \"require('nan')\")"
						],
						"link_settings": {
							"libraries": [
								"-lpcsclite"
							],
							"library_dirs": [
								"/usr/lib"
							]
						}
					}
				],
				[
					"OS=='mac'",
					{
						"libraries": [
							"-framework",
							"PCSC"
						],
						"include_dirs": [
							"<!(node -e \"require('nan')\")"
						],
						"xcode_settings": {
							"MACOSX_DEPLOYMENT_TARGET": "10.15",
							"ARCHS": ["x86_64", "arm64"]
						}
					}
				],
				[
					"OS=='win'",
					{
						"libraries": [
							"-lWinSCard"
						],
						"include_dirs": [
							"<!(node -e \"require('nan')\")"
						]
					}
				]
			]
		}
	]
}
