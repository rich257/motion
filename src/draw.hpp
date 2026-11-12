/*
 *    This file is part of Motion.
 *
 *    Motion is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Motion is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Motion.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef _INCLUDE_DRAW_HPP_
#define _INCLUDE_DRAW_HPP_
    #define ASCII_MAX 127
    #define NEWLINE "\\n"

    class cls_draw {
        public:
            cls_draw(cls_camera *p_cam);
            ~cls_draw();
            void text();
            void text_motion();
            void text_debug();
            void text_lost();
            void locate();
            void smartmask();
            void fixed_mask();
            void largest_label();
            void init_params();

        private:
            cls_camera  *cam;
            u_char      *char_arr_ptr[ASCII_MAX];
            bool        uselegacy;
            int         scalefactor;
            bool        showdiffs;


            std::string     ft_font;
            std::string     ft_color;
            int             ft_size;
            bool            ft_usersz;
            std::string     ft_flags;
            std::string     ft_textl;
            std::string     ft_textr;
            AVFilterGraph   *fltgr;
            const AVFilter  *fltsrc;
            const AVFilter  *fltdraw_tl;
            const AVFilter  *fltdraw_tr;
            const AVFilter  *fltdraw_bl;
            const AVFilter  *fltdraw_br;
            const AVFilter  *fltsink;
            AVFilterContext *fltctx_src;
            AVFilterContext *fltctx_draw_tl;
            AVFilterContext *fltctx_draw_tr;
            AVFilterContext *fltctx_draw_bl;
            AVFilterContext *fltctx_draw_br;
            AVFilterContext *fltctx_sink;
            AVFrame         *frm_in;
            AVFrame         *frm_out;

            ctx_params  *params;

            void init_chars();
            void init_ft();

            void text_legacy_ln(u_char *image, int stx, int sty
                ,const char *text, int len, int factor);
            void text_legacy(u_char *image, int stx, int sty
                , const char *text, int factor);
            void location(ctx_coord *cent
                , ctx_images *imgs, int width, u_char *new_var);
            void red_location(ctx_coord *cent
                , ctx_images *imgs, int width, u_char *new_var);
            void text_ft_base(u_char *image_norm
                , std::string txtl, std::string txtr
                , std::string txbl, std::string txbr);

    };

#endif /* _INCLUDE_DRAW_HPP_ */