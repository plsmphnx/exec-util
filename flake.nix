{
  outputs = { nixpkgs, ... }: let
    systems = fn: nixpkgs.lib.mapAttrs (_: fn) nixpkgs.legacyPackages;
  in {
    packages = systems (pkgs: {
      default = pkgs.stdenv.mkDerivation {
        name = "exec-util";
        src = ./.;
        buildPhase = ''
          for f in *.c; do gcc $f -o exec-''${f%.*}; done
        '';
        installPhase = ''
          mkdir -p "$out/bin"
          mv exec-* "$out/bin"
        '';
      };
    });
  };
}