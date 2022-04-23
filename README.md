# Minishell-42

# Table of content :
* [What is Minishell ?](#What-is-Minishell-)
* [What is in it ?](#what-is-in-it-)
* [How does is work ?](#how-does-is-work-)

### What is Minishell ?
 Minishell is a binome project at 42. The purpose is to learn how the shell works (man bash). You will implement pipe, fork, input commande.
 
 ### What is in it ?
 You will need to parcing the input of user, then execute.
<a href="https://zupimages.net/viewer.php?id=22/16/oyx9.png"><img src="https://zupimages.net/up/22/16/oyx9.png" alt="" /></a>

### How does is work ?
![Screen Recording 2022-04-23 at 10 53 57 AM](https://user-images.githubusercontent.com/89851173/164888128-7a2a4590-0d90-4d8e-a18b-69f5def921ce.gif)

### Dependencies
#### Install readline with [brew](https://brew.sh/)
```
brew install readline
```

```
brew link --force readline
```

Add the path to the lib

Replace ~/.zshrc with ~/.bashrc if you use bash instead of zsh
```
echo 'export C_INCLUDE_PATH="/usr/local/opt/readline/include:$C_INCLUDE_PATH"' >> ~/.zshrc
```
```
echo 'export LIBRARY_PATH="/usr/local/opt/readline/lib:$LIBRARY_PATH"' >> ~/.zshrc
```
```
source ~/.zshrc
```

#### Install readline on 42 Macs

Install Brew, <b>only if it is not already installed:</b>

```
rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update
```

Install Readline library:
```
brew install readline
```

```
brew link --force readline
```

```
echo 'export C_INCLUDE_PATH="$HOME/.brew/include:$C_INCLUDE_PATH"' >> ~/.zshrc
```

```
echo 'export LIBRARY_PATH="$HOME/.brew/lib:$LIBRARY_PATH"' >> ~/.zshrc
```
```
source ~/.zshrc
```
