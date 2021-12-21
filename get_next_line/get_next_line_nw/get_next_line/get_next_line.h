#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
 
#  define BUFFER_SIZE 42

# endif

/* Ruft nächste Zeile von file descriptor ab */
char	*get_next_line(int fd);

/* gibt länge des Strings wieder */
size_t	gnl_strlen(const char *s);

/* Ruft Index des ersten Auftretens von i in s, oder -1 */
int		gnl_strchr_i(const char *s, int c);

/* Kopiert chars von src nach dst und versichert null-termination */
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

/* Weißt genug Speicher zu und macht Kopie von s und start, kopiert len bytes */
char	*gnl_substr(char const *s, unsigned int start, size_t len);

/* verbindet zwei strings, versichert null-termination */
size_t	gnl_strlcat(char *dst, const char *src, size_t size);

/* löscht line von static variable buf */
char	*gnl_shrink_buffer(char *buf, char *line);

/* Führt einen neuen Lesevorgang durch und fügt ihn static variable buf hinzu*/
char	*gnl_expand_buffer(char *buf, int fd);

/* Führt neuen Lesevorgang durch und returns read string */
char	*gnl_newread(int fd);

#endif