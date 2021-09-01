(function(g){var window=this;'use strict';var X3=function(a){g.V.call(this,{D:"div",K:"ytp-miniplayer-ui"});this.Tg=!1;this.player=a;this.N(a,"minimized",this.Vh);this.N(a,"onStateChange",this.YC)},Y3=function(a){g.SL.call(this,a);
this.i=new X3(this.player);this.i.hide();g.IL(this.player,this.i.element,4);a.lf()&&(this.load(),g.L(a.getRootNode(),"ytp-player-minimized",!0))};
g.v(X3,g.V);g.k=X3.prototype;
g.k.sB=function(){this.tooltip=new g.lP(this.player,this);g.H(this,this.tooltip);g.IL(this.player,this.tooltip.element,4);this.tooltip.scale=.6;this.pc=new g.IM(this.player);g.H(this,this.pc);this.eh=new g.V({D:"div",K:"ytp-miniplayer-scrim"});g.H(this,this.eh);this.eh.xa(this.element);this.N(this.eh.element,"click",this.Fx);var a=new g.V({D:"button",Ba:["ytp-miniplayer-close-button","ytp-button"],U:{"aria-label":"Close"},S:[g.PJ()]});g.H(this,a);a.xa(this.eh.element);this.N(a.element,"click",this.Gi);
a=new g.y_(this.player,this);g.H(this,a);a.xa(this.eh.element);this.Oo=new g.V({D:"div",K:"ytp-miniplayer-controls"});g.H(this,this.Oo);this.Oo.xa(this.eh.element);this.N(this.Oo.element,"click",this.Fx);var b=new g.V({D:"div",K:"ytp-miniplayer-button-container"});g.H(this,b);b.xa(this.Oo.element);a=new g.V({D:"div",K:"ytp-miniplayer-play-button-container"});g.H(this,a);a.xa(this.Oo.element);var c=new g.V({D:"div",K:"ytp-miniplayer-button-container"});g.H(this,c);c.xa(this.Oo.element);this.mJ=new g.iO(this.player,
this,!1);g.H(this,this.mJ);this.mJ.xa(b.element);b=new g.fO(this.player,this);g.H(this,b);b.xa(a.element);this.nextButton=new g.iO(this.player,this,!0);g.H(this,this.nextButton);this.nextButton.xa(c.element);this.gh=new g.ZO(this.player,this);g.H(this,this.gh);this.gh.xa(this.eh.element);this.Ec=new g.nO(this.player,this);g.H(this,this.Ec);g.IL(this.player,this.Ec.element,4);this.tx=new g.V({D:"div",K:"ytp-miniplayer-buttons"});g.H(this,this.tx);g.IL(this.player,this.tx.element,4);a=new g.V({D:"button",
Ba:["ytp-miniplayer-close-button","ytp-button"],U:{"aria-label":"Close"},S:[g.PJ()]});g.H(this,a);a.xa(this.tx.element);this.N(a.element,"click",this.Gi);a=new g.V({D:"button",Ba:["ytp-miniplayer-replay-button","ytp-button"],U:{"aria-label":"Close"},S:[g.UJ()]});g.H(this,a);a.xa(this.tx.element);this.N(a.element,"click",this.DR);this.N(this.player,"presentingplayerstatechange",this.xc);this.N(this.player,"appresize",this.kb);this.N(this.player,"fullscreentoggled",this.kb);this.kb()};
g.k.show=function(){this.Fd=new g.$m(this.yp,null,this);this.Fd.start();this.Tg||(this.sB(),this.Tg=!0);0!==this.player.getPlayerState()&&g.V.prototype.show.call(this);this.Ec.show();this.player.unloadModule("annotations_module")};
g.k.hide=function(){this.Fd&&(this.Fd.dispose(),this.Fd=void 0);g.V.prototype.hide.call(this);this.player.lf()||(this.Tg&&this.Ec.hide(),this.player.loadModule("annotations_module"))};
g.k.oa=function(){this.Fd&&(this.Fd.dispose(),this.Fd=void 0);g.V.prototype.oa.call(this)};
g.k.Gi=function(){this.player.stopVideo();this.player.La("onCloseMiniplayer")};
g.k.DR=function(){this.player.playVideo()};
g.k.Fx=function(a){if(a.target===this.eh.element||a.target===this.Oo.element)g.S(this.player.T().experiments,"kevlar_miniplayer_play_pause_on_scrim")?g.SI(this.player.rb())?this.player.pauseVideo():this.player.playVideo():this.player.La("onExpandMiniplayer")};
g.k.Vh=function(){g.L(this.player.getRootNode(),"ytp-player-minimized",this.player.lf())};
g.k.Ie=function(){this.Ec.Sb();this.gh.Sb()};
g.k.yp=function(){this.Ie();this.Fd&&this.Fd.start()};
g.k.xc=function(a){g.U(a.state,32)&&this.tooltip.hide()};
g.k.kb=function(){g.yO(this.Ec,0,this.player.Wa().getPlayerSize().width,!1);g.pO(this.Ec)};
g.k.YC=function(a){this.player.lf()&&(0===a?this.hide():this.show())};
g.k.dc=function(){return this.tooltip};
g.k.Xe=function(){return!1};
g.k.nf=function(){return!1};
g.k.Ci=function(){return!1};
g.k.dy=function(){};
g.k.Om=function(){};
g.k.Sq=function(){};
g.k.cn=function(){return null};
g.k.mj=function(){return new g.Xf(0,0,0,0)};
g.k.handleGlobalKeyDown=function(){return!1};
g.k.handleGlobalKeyUp=function(){return!1};
g.k.Gp=function(a,b,c,d,e){var f=0,h=d=0,l=g.sg(a);if(b){c=g.jn(b,"ytp-prev-button")||g.jn(b,"ytp-next-button");var m=g.jn(b,"ytp-play-button"),n=g.jn(b,"ytp-miniplayer-expand-watch-page-button");c?f=h=12:m?(b=g.qg(b,this.element),h=b.x,f=b.y-12):n&&(h=g.jn(b,"ytp-miniplayer-button-top-left"),f=g.qg(b,this.element),b=g.sg(b),h?(h=8,f=f.y+40):(h=f.x-l.width+b.width,f=f.y-20))}else h=c-l.width/2,d=25+(e||0);b=this.player.Wa().getPlayerSize().width;e=f+(e||0);l=g.be(h,0,b-l.width);e?(a.style.top=e+"px",
a.style.bottom=""):(a.style.top="",a.style.bottom=d+"px");a.style.left=l+"px"};
g.k.showControls=function(){};
g.k.al=function(){};
g.k.Ck=function(){return!1};g.v(Y3,g.SL);Y3.prototype.create=function(){};
Y3.prototype.Si=function(){return!1};
Y3.prototype.load=function(){this.player.hideControls();this.i.show()};
Y3.prototype.unload=function(){this.player.showControls();this.i.hide()};g.YL.miniplayer=Y3;})(_yt_player);
