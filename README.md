
# Manga Updates

This is a Simple Command line Utility For Unix System made to help keep track of releases English versions of manga. This Tool uses the Manga Updates Rest Api for its data.




## Authors

- [@DanielB](https://gitlab.danielsworkbench.com/DanielB) Lead Developer


## Installation

You will need to install some make Dependencies

Automatic
```bash
  #Clone and Install the latest stable github release
  git clone https://github.com/danielbyomujuni/mangamanager.git
  yay -Bi mangaupdates/pkg
```

Manual
```bash
    #Install Dependencies (Arch Linux)
    yay -S cmake curl nlohmann-json
    
    git clone https://github.com/danielbyomujuni/mangamanager.git
    cd mangamanager
    cmake -B .build \
            -DCMAKE_BUILD_TYPE='Release' \
            -DCMAKE_INSTALL_PREFIX='/usr' \
            -Wno-dev
    cmake --build .build
    cmake --install .build
```