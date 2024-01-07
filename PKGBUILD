# Maintainer: Daniel Byomujuni <danielbyomujuni@gmail.com>
pkgname='mangamanager'
pkgver=1.0.0
pkgrel=1
pkgdesc="A Command line CLI for managing your manga collection"
arch=('x86_64')
url="https://github.com/danielbyomujuni/MangaUpdates"
license=('GPL')
groups=()
depends=()
makedepends=('nlohmann-json' 'curl' 'git')
checkdepends=()
optdepends=()
provides=('package')
source=('git+https://github.com/danielbyomujuni/mangamanager.git')
md5sums=('SKIP')


pkgver() {
    cd "$pkgname"
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
    cd "$pkgname"
    cmake -S ./  -B .build/
    cmake --build .build/ --target mangamanager
}
rm
package() {
    cd "$pkgname"
    cd ".build"
    make install mangamanaer
}