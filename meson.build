project('shited', 'cpp', version: '0.0.0a', default_options: ['cpp_std=c++17'])

ncurses_dep = dependency('ncurses', required: true)

sources = files('src/main.cpp', 'src/buffer.cpp', 'src/editor.cpp', 'src/piece_table.cpp', 'src/ui.cpp')

executable('shited', sources, dependencies: [ncurses_dep], install: true)