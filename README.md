# 42_libs_c of bamagere

Collection personnelle de bibliothèques C : Libft, ft_printf/fd_printf,
get_next_line et utilitaires réutilisables.

```sh
make -j4     # libft/libft.a, gnl/libgnl.a, printfs/libftprintf.a
make norm    # Norminette et documentation des fonctions de bibliothèque
make check   # compilation et tous les contrôles
```

`clean`, `fclean`, `re`, `bonus` et les cibles `libft`, `gnl`, `printfs`
sont disponibles dans le Makefile principal. Les trois archives restent dans leurs sous-dossiers.


Norminette vise les sources et headers de `libft/`, `gnl/` et `printfs/`.
