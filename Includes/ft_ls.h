/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:15:16 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 04:00:27 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/Includes/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_dir
{
	char			*path_dir;
	char			*path_obj;
	char			*obj;
	char			path_lnk[1024];
	struct stat		inf;
	struct stat		inflnk;
	struct stat		infent;
	DIR				*opdir;
	struct dirent	*ent;
	int				error;
	char			type;
	int				cdirs;
	int				cobjs;
}					t_dir;

typedef struct		s_flags
{
	int				col;
	int				gr;
	int				a;
	int				l;
	int				pr;
	int				t;
	int				g;
	int				gg;
	int				ga;
	int				o;
	int				error;
}					t_flags;

typedef struct		s_info
{
	unsigned long	totblocks;
}					t_info;

typedef struct		s_infsiz
{
	int				lnk;
	int				usr;
	int				grp;
	int				maj;
	int				min;
	int				siz;
}					t_infsiz;

typedef struct		s_var
{
	int				have_files;
	int				have_dirs;
	int				i;
	int				j;
	int				y;
}					t_var;

typedef struct		s_parms
{
	t_flags			flags;
	t_info			info;
	t_infsiz		infsiz;
	char			**to_list;
	int				obj_to_list;
	t_dir			cur_dir;
	int				is_var;
	int				have_fts;
	char			**files;
	char			**dirs;
	t_var			var;

}					t_parms;

typedef struct		s_sort
{
	int				lft;
	int				rht;
	char			*piv;
	char			*tmp;
	char			*pth;
	char			**tab;
	char			*pthlft;
	char			*pthrht;
	char			*pthpiv;
}					t_sort;

typedef struct		s_rec
{
	int				l;
	char			*path_ent;
	char			type;
	char			**tab_dirs;
	int				i;
}					t_rec;

/*
**			error.c			2
*/
void				print_error_flags(char c);
void				print_error_open(char *obj, t_parms parms);
/*
**			flags.c			3
*/
t_flags				flagged(t_flags flags, char *parm, int c);
t_flags				not_flagged(t_flags flags);
t_flags				error_flag(t_flags flags);
t_flags				flagged_col(t_flags flags);
t_flags				flagged_a(t_flags flags);
/*
**			flags_2.c			3
*/
t_flags				flagged_l(t_flags flags);
t_flags				flagged_g(t_flags flags);
t_flags				flagged_ga(t_flags flags);
t_flags				flagged_o(t_flags flags);
t_flags				flag_it(t_flags flags, char c);
/*
**			create_tab.c	2
*/
char				**crt_tab_parms(int num_parms, char **parms, int p);
char				**crt_tab_void(int num_objs);
/*
**			exec.c			5
*/
void				exec(t_parms parms);
void				exec_one_obj(t_parms parms);
void				exec_one_obj_fl(t_parms parms);
void				exec_one_obj_fal(t_parms parms);
void				exec_one_obj_fa(t_parms parms);
/*
**			exec_2.c		5
*/
void				exec_one_obj_ft(t_parms parms);
void				exec_one_obj_flt(t_parms parms);
void				exec_one_obj_falt(t_parms parms);
void				exec_one_obj_fat(t_parms parms);
void				exec_one_obj_fr(t_parms parms);
/*
**			exec_3.c		5
*/
void				exec_one_obj_far(t_parms parms);
void				exec_one_obj_flr(t_parms parms);
void				exec_one_obj_falr(t_parms parms);
void				exec_one_obj_ftr(t_parms parms);
void				exec_one_obj_fatr(t_parms parms);
/*
**			exec_4.c		5
*/
void				exec_one_obj_fltr(t_parms parms);
void				exec_one_obj_faltr(t_parms parms);
t_parms				exec_one_lnk(t_parms parms);
void				exec_cur_dir_def(t_parms parms);
void				exec_cur_dir_long_def(t_parms parms);
/*
**			exec_5.c		5
*/
void				exec_cur_dir_time_def(t_parms parms);
void				exec_cur_dir_time_long(t_parms parms);
void				exec_cur_dir_rev(t_parms parms);
void				exec_cur_dir_long_rev(t_parms parms);
void				exec_cur_dir_time_rev(t_parms parms);
/*
**			exec_6.c		5
*/
void				exec_cur_dir_time_long_rev(t_parms parms);
void				exec_one(t_parms parms);
void				exec_long(t_parms parms);
t_parms				exec_one_lnk_fr(t_parms parms);
t_parms				exec_one_lnk_far(t_parms parms);
/*
**			exec_7.c		5
*/
t_parms				exec_one_lnk_fat(t_parms parms);
t_parms				exec_one_lnk_ft(t_parms parms);
t_parms				exec_one_lnk_fatr(t_parms parms);
t_parms				exec_one_lnk_ftr(t_parms parms);
t_parms				exec_one_lnk_fa(t_parms parms);

/*
**			exec_8.c		5
*/
void				exec_one_fa(t_parms parms);
void				exec_cur_dir_rec(t_parms parms);
void				exec_cur_dir_def_rec(t_parms parms);
void				exec_rec_def(char *dir, t_parms parms);
void				exec_cur_dir_time_def(t_parms parms);
/*
**			exec_9.c		5
*/
void				exec_rec_ft(char *dir, t_parms parms);
void				exec_cur_dir_fr_rec(t_parms parms);
void				exec_rec_rev(char *dir, t_parms parms);
void				exec_cur_dir_long_def_rec(t_parms parms);
void				exec_rec_long(char *dir, t_parms parms);
/*
**			exec_10.c		5
*/
void				exec_cur_dir_frt_rec(t_parms parms);
void				exec_rec_time_rev(char *dir, t_parms parms);
void				exec_cur_dir_time_long_rec(t_parms parms);
void				exec_rec_time_long(char *dir, t_parms parms);
void				exec_cur_dir_time_long_rev_rec(t_parms parms);
void				exec_rec_time_long_rev(char *dir, t_parms parms);
/*
**			exec_11.c		3
*/
void				exec_rec_time_long_rev(char *dir, t_parms parms);
void				exec_one_rec(t_parms parms);
void				exec_one_def_rec(char *dir, t_parms parms, int first);
void				exec_one_lnk_rec(t_parms parms);
void				exec_one_dirlnk_def_rec(t_parms parms);
/*
**			exec_12.c		5
*/
void				exec_one_ft_rec(char *dir, t_parms parms, int first);
void				exec_one_dirlnk_time_def_rec(t_parms parms);
void				exec_one_fr_rec(char *dir, t_parms parms, int first);
void				exec_one_dirlnk_rev_def_rec(t_parms parms);
void				exec_one_fl_rec(char *dir, t_parms parms, int first);
/*
**			exec_13.c		5
*/
void				exec_one_dirlnk_long_def_rec(t_parms parms);
void				exec_one_frt_rec(char *dir, t_parms parms, int first);
void				exec_one_dirlnk_frt_rec(t_parms parms);
void				exec_one_flt_rec(char *dir, t_parms parms, int first);
void				exec_one_dirlnk_flt_rec(t_parms parms);
/*
**			exec_14.c		5
*/
void				exec_one_fltr_rec(char *dir, t_parms parms, int first);
void				exec_one_dirlnk_fltr_rec(t_parms parms);
void				exec_var(t_parms parms);
void				exec_rec_long_rev(char *dir, t_parms parms);
void				exec_cur_dir_long_rev_rec(t_parms parms);
/*
**			exec_15.c		2
*/
void				exec_one_dir(t_parms parms);
void				exec_var_run(t_parms parms, int j, int y);
/*
**			init.c			5
*/
t_parms				init_path(char *obj, t_parms parms);
t_parms				init_path_lnk(char *path, t_parms parms);
t_parms				init_path_obj(char *path, t_parms parms);
t_parms				init_path_dir(char *path, t_parms parms);
t_parms				init_dir(char *obj, t_parms parms);
/*
**			init_2.c		2
*/
t_parms				init_path_null(char *path, t_parms parms);
t_parms				init_info_for_padding(t_parms parms);
/*
**			types.c			4
*/
char				type_parm(t_parms parms);
char				type_obj(t_parms parms);
char				type_lnk(t_parms parms);
int					is_system(char *obj);
int					is_shadow(char *obj);
/*
**			conv_str.c		5
*/
char				*rmv_path_frm_obj(char *path);
char				*rmv_obj_frm_path(char *path);
char				*path_it(char *dir, char *obj);
char				*convstr_path_if(char *dir, char *obj);
/*
**			open_close.c	1
*/
t_parms				open_dir(char *obj, t_parms parms);
void				close_dir(t_parms parms);
t_parms				open_new_dir(t_parms parms);
/*
**			clear.c			3
*/
void				clear_dir(t_dir cur_dir);
void				clear_dir_error(t_dir cur_dir);
t_dir				reset_dir_error(t_dir cur_dir);
/*
**			checks.c		3
*/
int					check_for_time(t_parms parms);
char				*check_path_obj(char *obj);
t_parms				check_init_path(char *path, char *obj, t_parms parms);
int					check_for_fts(t_parms parms);
/*
**			scan.c			5
*/
t_parms				scan_dir_no_flags(t_parms parms);
t_parms				scan_dir_fa(t_parms parms);
t_parms				scan_dir_fl(t_parms parms);
t_parms				scan_dir_fal(t_parms parms);
t_parms				scan_obj_no_flags(t_parms parms);
/*
**			scan_2.c 		5
*/
t_parms				scan_obj_fl(t_parms parms);
void				scan_print_dirlnk_fa(t_parms parms);
void				scan_print_dirlnk(t_parms parms);
t_parms				scan_lnk(t_parms parms);
t_parms				scan_dirlnk_no_flags(t_parms parms);
/*
**			scan_3.c 		3
*/
t_parms				scan_dirlnk_fa(t_parms parms);
t_parms				scan_dirlnk_fl(t_parms parms);
t_parms				scan_dirlnk_fal(t_parms parms);
/*
**			info.c			5
*/
unsigned long		get_block_size(t_parms parms);
int					get_nlinks(t_parms parms);
char				*get_user(t_parms parms);
char				*get_group(t_parms parms);
t_parms				get_info_for_padding(t_parms parms, int ctrl, char type);
/*
**			info_2.c		5
*/
int					get_major(t_parms parms);
int					get_minor(t_parms parms);
t_parms				get_info_for_pad_majmin(t_parms parms);
int					get_size(t_parms parms);
int					have_set_uid(t_parms parms);
/*
**			info_3.c		4
*/
int					have_set_gid(t_parms parms);
int					have_sticky(t_parms parms);
char				*get_time_mod(t_parms parms);
long int			get_time_mod_rint(char *obj);
t_parms				get_info_for_padding_var(t_parms parms, int i);
/*
**			apply.c			1
*/
void				apply_long(t_parms parms, char *path_ent);
/*
**			put.c			5
*/
void				put_rights(t_parms parms, char *path_ent);
void				put_nlinks(t_parms parms);
void				put_user(t_parms parms);
void				put_group(t_parms parms);
void				put_mtime(t_parms parms);
/*
**			puts_2.c		5
*/
void				put_size(t_parms parms);
void				put_major(t_parms parms);
void				put_minor(t_parms parms);
void				put_link(char *obj, char *path, t_parms parms);
void				put_dir(char *obj, t_parms parms);
/*
**			puts_3.c		1
*/
void				put_link_obj(char *obj, t_parms parms);
void				put_time_year(t_parms parms, char *tmp);
void				put_total_blocks(t_parms parms);
void				put_desc(char *dir);
/*
**			put_rights.c	3
*/
void				put_rights_user(t_parms parms);
void				put_rights_group(t_parms parms);
void				put_rights_others(t_parms parms);
/*
**			put_rights_special.c	3
*/
void				put_rights_usrsp(t_parms parms);
void				put_rights_grpsp(t_parms parms);
void				put_rights_othsp(t_parms parms);
/*
**			rights.c		3
*/
int					rights_user(t_parms parms);
int					rights_group(t_parms parms);
int					rights_others(t_parms parms);
/*
**			list.c			5
*/
char				**list_dir_no_flags(t_parms parms);
char				**list_dir_fa(t_parms parms);
char				**list_dir_ft(t_parms parms);
char				**list_dir_fat(t_parms parms);
char				**list_dirlnk_no_flags(t_parms parms);
/*
**			list_2.c		3
*/
char				**list_dirlnk_fa(t_parms parms);
char				**list_dirlnk_ft(t_parms parms);
char				**list_dirlnk_fat(t_parms parms);
/*
**			sort.c			3
*/
char				**sort_alph(char **tab, int cnt_obj);
char				**sort_tab_dmodif(char **tab, char *path, int cnt_obj);
/*
**			utils.c			5
*/
t_sort				swap(t_sort s);
int					cmp_time(char *obj1, char *obj2);
void				run_var_dirs(char **dirs, char **files, t_parms parms);
void				run_var_files(char **files, t_parms parms, int i);
/*
**			utils_2.c		5
*/
t_parms				tab_it(t_parms parms, int i, int j);
t_parms				fill_var_tab(t_parms parms);
/*
**			utils_3.c		5
*/
char				**return_for_list_ft(t_parms parms, char **entrys);
t_rec				tab_it_for_print_rec(t_rec rec, t_parms parms, char **list);
t_rec				tab_it_for_print_fr_rec(t_rec rec, t_parms parms,
						char **list);
t_rec				tab_it_for_print_fl_rec(t_rec rec, t_parms parms,
						char **list);
t_rec				put_and_tab_dir(t_rec rec, char **list, t_parms parms);
/*
**			utils_4.c		5
*/
t_rec				tab_it_for_print_flr_rec(t_rec rec, t_parms parms,
						char **list);
t_rec				tab_it_for_print_lnk_rec(t_rec rec, t_parms parms,
						char **list);
t_rec				tab_it_for_print_lnk_fr_rec(t_rec rec, t_parms parms,
						char **list);
t_rec				tab_it_for_print_lnk_fl_rec(t_rec rec, t_parms parms,
						char **list);
t_rec				tab_it_for_print_lnk_flr_rec(t_rec rec, t_parms parms,
						char **list);
/*
**			utils_5.c		2
*/
void				print_tab_dirs_def(t_parms parms, char **dirs);
void				print_tab_dirs_rev(t_parms parms, char **dirs);
/*
**			print.c			5
*/
void				print_list(char **list, t_parms parms);
void				print_list_fl(char **list, t_parms parms);
void				print_list_fr(char **list, t_parms parms);
void				print_list_flr(char **list, t_parms parms);
void				print_list_lnk(char **list, t_parms parms);
/*
**			print_2.c		5
*/
void				print_list_lnk_fr(char **list, t_parms parms);
char				**print_list_rec(char **list, t_parms parms);
char				**print_list_fr_rec(char **list, t_parms parms);
char				**print_list_fl_rec(char **list, t_parms parms);
char				**print_list_flr_rec(char **list, t_parms parms);
/*
**			print_3.c		4
*/
char				**print_list_lnk_rec(char **list, t_parms parms);
char				**print_list_lnk_fr_rec(char **list, t_parms parms);
char				**print_list_lnk_fl_rec(char **list, t_parms parms);
char				**print_list_lnk_flr_rec(char **list, t_parms parms);
/*
**			display.c		5
*/
void				display_dir_def(t_parms parms);
void				display_file_def(t_parms parms);
void				display_dir_fl(t_parms parms);
void				display_link_fl(t_parms parms);
void				display_file_fl(t_parms parms);
/*
**			display_2.c		5
*/
void				display_dir_ft(t_parms parms);
void				display_dir_flt(t_parms parms);
void				display_dir_fr(t_parms parms);
void				display_dir_flr(t_parms parms);
void				display_dir_ftr(t_parms parms);
/*
**			display_3.c		5
*/
void				display_dir_fltr(t_parms parms);
char				**display_dir_for_rec_def(t_parms parms);
char				**display_dir_for_rec_ft(t_parms parms);
char				**display_dir_for_rec_fr(t_parms parms);
char				**display_dir_for_rec_fl(t_parms parms);
/*
**			display_4.c		5
*/
char				**display_dir_for_rec_frt(t_parms parms);
char				**display_dir_for_rec_ftl(t_parms parms);
char				**display_dir_for_rec_frtl(t_parms parms);
char				**display_dirlnk_for_rec_def(t_parms parms);
char				**display_dirlnk_for_rec_ft(t_parms parms);
/*
**			display_5.c		5
*/
char				**display_dirlnk_for_rec_fr(t_parms parms);
char				**display_dirlnk_for_rec_fl(t_parms parms);
char				**display_dirlnk_for_rec_frt(t_parms parms);
char				**display_dirlnk_for_rec_flt(t_parms parms);
char				**display_dirlnk_for_rec_fltr(t_parms parms);
char				**display_dir_for_rec_frl(t_parms parms);
/*
**			display_6.c		1
*/

#endif
