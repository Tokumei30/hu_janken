
$(function () {
    /* 画像 */
    var img_ta = new Image();
    img_ta.src = "img/_to_about.png";

    var img_tf = new Image();
    img_tf.src = "img/to_fjan.png";

    /* 初期値 */
    $('.to').css("opacity", "0");
    $(".to_about_image img").css({
        "opacity": "0",
        "height": img_ta.height / img_ta.width * 100 + "vw",
        "width": "20vw"
    })
    $(".to_fjan_image img").css({
        "opacity": "0",
        "height": "0",
        "width": img_tf.width / img_tf.height * 100 + "vh"
    })

    /* 画面領域内に入ったときの処理 */
    $(window).scroll(function () {
        $(".to").each(function () {
            var imgPos = $(this).offset().top;
            var scroll = $(window).scrollTop();
            var windowHeight = $(window).height();
            if (scroll > imgPos - windowHeight + windowHeight / 3) {
                $(this).css("opacity", "1");
            } else {
                $(this).css("opacity", "0");
            }
        });

        $(".to_about_image img").each(function () {
            var imgPos = $(this).offset().top;
            var scroll = $(window).scrollTop();
            var windowHeight = $(window).height();
            if (scroll > imgPos - windowHeight + windowHeight / 3) {
                $(this).css({
                    "opacity": "1",
                    "width": "100vw"
                })
            } else {
                $(this).css({
                    "opacity": "0",
                    "width": "20vw"
                })
            }
        });

        $(".to_fjan").each(function () {
            var imgPos = $(this).offset().top;
            var scroll = $(window).scrollTop();
            var windowHeight = $(window).height();
            if (scroll > imgPos - windowHeight + windowHeight / 3) {
                $(this).parent().css("background-color", "#000000");
            } else {
                $(this).parent().css("background-color", "#ffffff");
            }
        });

        $(".to_fjan_image img").each(function () {
            var imgPos = $(this).offset().top;
            var scroll = $(window).scrollTop();
            var windowHeight = $(window).height();
            if (scroll > imgPos - windowHeight * 1.2) {
                $(this).css({
                    "opacity": "1",
                    "height": "660px"
                })
            } else {
                $(this).css({
                    "opacity": "0",
                    "height": "0"
                })
            }
        });

        $(".recent").each(function () {
            var imgPos = $(this).offset().top;
            var scroll = $(window).scrollTop();
            var windowHeight = $(window).height();
            if (scroll > imgPos - windowHeight + windowHeight / 3) {
                $(this).parent().css("background-color", "#ffffff");
            }
        });
    });
});