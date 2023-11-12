{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    
  };
  outputs = {self,nixpkgs}: {
    defaultPackage.aarch64-linux =
      with import nixpkgs {system = "aarch64-linux";};
      stdenv.mkDerivation {
        name = "kilo-c";
        src = self;
        # buildPhase = "ls";
        buildInputs = [pkgs.gcc];
        nativeBuildInputs = [pkgs.pkg-config];
        buildPhase = ''
                   gcc -Wall -Wextra -std=c99 -pedantic -ggdb -o kilo-c ./src/main.c
        '';
        installPhase = "mkdir -p $out/bin; install -t $out/bin kilo-c";
      };
  };
}

#  `pkg-config --cflags sdl2 SDL2_ttf ` -o hello ./from_scratch.c `pkg-config --libs sdl2 SDL2_ttf` -lm
                     # gcc -Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags sdl2 sdl2_ttf ` -o hello ./pikuma.c `pkg-config --libs sdl2 sdl2_ttf` -lm
