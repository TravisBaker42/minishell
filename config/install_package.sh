#!/bin/sh

# check if package has been installed
is_installed() {
	dpkg -l "$1" &> /dev/null
}

# function to install packages if not already installed
install_package() {
	PACKAGE=$1
	if is_installed "$PACKAGE"; then
		echo "$PACKAGE is already installed :)"
	else
		echo "Installing $PACKAGE...."
		sudo apt-get install -y "$PACKAGE"
	fi
}

# Function to install vim plug if not already installed
install_vimplug() {
	VIM_PLUG_PATH="$HOME/.vim/autoload/plug.vim"
	if [ -f "$VIM_PLUG_PATH" ]; then
		echo "vim-plug is already installed."
	else
		echo "installing vim-plug..."
		curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
			https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
		echo "vim-plug installed successfully :)"
	fi
}

# updates and upgrades system
sudo apt-get update -y
sudo apt-get upgrade -y

# array/list of packages to install
PACKAGES=("git" "vim" "curl" "vlc" "libreadline-dev" "valgrind")

# installs each package
for PACKAGE in "${PACKAGES[@]}"; do
	install_package "$PACKAGE"
done

# installs vim-plug
install_vimplug

echo "Install complete (_)_)=========[]"
