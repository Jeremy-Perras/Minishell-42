# libft-42 

## Table of content :
* [What is libft ?](#what-is-libft-)
* [What is it ?](#what-is-in-it-)
* [How does is work ?](#how-does-is-work-)

### What is libft ?
  Libft is a individual project at 42 re-create some standart C library functions and some additionnal that can be used for later. The purpose is to understand the basic of algorithms and structure.

### What is in it ?

Libc functions | Additional functions | Bonus Functions 
:----------- | :-----------: | :-----------: | 
isalpha		   | ft_substr	   | ft_lstnew		 |
isdigit	     | ft_strjoin		 | ft_lstadd_front|
isalnum	   | ft_strstrim		 | ft_lstsize		  |
isascii		   | ft_split		   | ft_lstlast	    |
isprint		   | ft_itoa		   | ft_lstadd_back	|
strlen	     | ft_strmapi	   | ft_lstdelone		|
memset		   | ft_striteri	 |	ft_lstclear   |
bzero		   | ft_putchar_fd	 |	ft_lsttiter   |
memcpy		   | ft_putstr_fd	 |	ft_lstmap     |
memmove		   | ft_putendl_fd |			          |
strlcpy		   | ft_putnbr_fd	 |		            |
strlcat		   | 	| |
toupper		   |  | |
tolower		   |  | |
strchr		   |  | |
strrchr		   |  | |
strncmp		   |  | |
memchr		   | 	| |
memcmp		   |  | |
strnstr		   |  | |
atoi		     |  | |
calloc		   |  | |
strdup		   |  | |

### How does is work ?
  The Makefile contain 4 rules : all clean fclean and re.
Create a library called libft.a. Later link this library with -L libft -lft.
