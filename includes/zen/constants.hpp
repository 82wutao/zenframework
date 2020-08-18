#ifndef __ZEN_FRAMEWORK_CONST_HPP
#define __ZEN_FRAMEWORK_CONST_HPP

namespace zen
{
namespace constants
{
/**
* GET	请求指定的页面信息，并返回实体主体。
* */
const char* METHOD_GET_STR = "GET";

/**
 *HEAD	类似于 GET 请求，只不过返回的响应中没有具体的内容，用于获取报头
 * */
const char* METHOD_HEAD_STR = "HEAD";

/**
* POST 向指定资源提交数据进行处理请求（例如提交表单或者上传文件）。数据被包含在请求体中。POST 请求可能会导致新的资源的建立和/或已有资源的修改。
* */
const char* METHOD_POST_STR = "POST";

/**
 * PUT	从客户端向服务器传送的数据取代指定的文档的内容。
 * */
const char* METHOD_PUT_STR = "PUT";

/**
 *DELETE	请求服务器删除指定的页面。
 * */
const char* METHOD_DELETE_STR = "DELETE";

/**
*CONNECT	HTTP/1.1 协议中预留给能够将连接改为管道方式的代理服务器。
* */
const char* METHOD_CONNECT_STR = "CONNECT";
/**
* OPTIONS 	允许客户端查看服务器的性能。
* */
const char* METHOD_OPTIONS_STR = "OPTIONS";

/**
 *TRACE	回显服务器收到的请求，主要用于测试或诊断。
 * */
const char* METHOD_TRACE_STR = "TRACE";

/**
*PATCH	是对 PUT 方法的补充，用来对已知资源进行局部更新 。
* */
const char* METHOD_PATCH_STR = "PATCH";

enum Http_Method {
    GET	= 1,
    HEAD= 1<<1,
    POST= 1<<2,
    PUT=1<<3,
    DELETE=1<<4,
    CONNECT =1<<5,
    OPTIONS=1<<6,
    TRACE=1<<7,
    PATCH=1<<8
};



struct statucode {
    const int code;
    const char* status;
};
typedef struct statucode StatusCode;

/**	继续。客户端应继续其请求 */
const StatusCode STATUSCODE_100= {100, 	"Continue"};
/** 切换协议。服务器根据客户端的请求切换协议。只能切换到更高级的协议，例如，切换到HTTP的新版本协议*/
const StatusCode STATUSCODE_101= { 	101,"Switching Protocols"};
/** 请求成功。一般用于GET与POST请求 */
const StatusCode STATUSCODE_200= {200, 	"OK"};
/** 已创建。成功请求并创建了新的资源 */
const StatusCode STATUSCODE_201= {201,"Created"};
/** 已接受。已经接受请求，但未处理完成 */
const StatusCode STATUSCODE_202 	= {202,"Accepted"};
/** 非授权信息。请求成功。但返回的meta信息不在原始的服务器，而是一个副本 */
const StatusCode STATUSCODE_203 	= {203,"Non-Authoritative Information"};
/** 无内容。服务器成功处理，但未返回内容。在未更新网页的情况下，可确保浏览器继续显示当前文档 */
const StatusCode STATUSCODE_204 	= {204,"No Content"};
/** 重置内容。服务器处理成功，用户终端（例如：浏览器）应重置文档视图。可通过此返回码清除浏览器的表单域 */
const StatusCode STATUSCODE_205 	= {205,"Reset Content"};
/** 部分内容。服务器成功处理了部分GET请求 */
const StatusCode STATUSCODE_206 	= {206,"Partial Content"};
/** 多种选择。请求的资源可包括多个位置，相应可返回一个资源特征与地址的列表用于用户终端（例如：浏览器）选择 */
const StatusCode STATUSCODE_300 	= {300,"Multiple Choices"};
/** 永久移动。请求的资源已被永久的移动到新URI，返回信息会包括新的URI，浏览器会自动定向到新URI。今后任何新的请求都应使用新的URI代替 */
const StatusCode STATUSCODE_301 	= {301,"Moved Permanently"};
/** 临时移动。与301类似。但资源只是临时被移动。客户端应继续使用原有URI */
const StatusCode STATUSCODE_302 	= {302,"Found"};
/** 查看其它地址。与301类似。使用GET和POST请求查看 */
const StatusCode STATUSCODE_303 	= {303,"See Other"};
/** 未修改。所请求的资源未修改，服务器返回此状态码时，不会返回任何资源。客户端通常会缓存访问过的资源，通过提供一个头信息指出客户端希望只返回在指定日期之后修改的资源 */
const StatusCode STATUSCODE_304 	= {304,"Not Modified"};
/** 使用代理。所请求的资源必须通过代理访问 */
const StatusCode STATUSCODE_305 	= {305,"Use Proxy"};
/** 已经被废弃的HTTP状态码 */
const StatusCode STATUSCODE_306 	= {306,"Unused"};
/** 临时重定向。与302类似。使用GET请求重定向 */
const StatusCode STATUSCODE_307 	= {307,"Temporary Redirect"};
/** 客户端请求的语法错误，服务器无法理解 */
const StatusCode STATUSCODE_400 	= {400,"Bad Request"};
/** 请求要求用户的身份认证 */
const StatusCode STATUSCODE_401 	= {401,"Unauthorized"};
/** Payment Required 	保留，将来使用 */
const StatusCode STATUSCODE_402= {402,"Payment Required"};
/** 服务器理解请求客户端的请求，但是拒绝执行此请求 */
const StatusCode STATUSCODE_403 	= {403,"Forbidden"};
/** 服务器无法根据客户端的请求找到资源（网页）。通过此代码，网站设计人员可设置"您所请求的资源无法找到"的个性页面 */
const StatusCode STATUSCODE_404 	= {404,"Not Found"};
/** 客户端请求中的方法被禁止 */
const StatusCode STATUSCODE_405 	= {405,"Method Not Allowed"};
/** 服务器无法根据客户端请求的内容特性完成请求 */
const StatusCode STATUSCODE_406 	= {406,"Not Acceptable"};
/** 请求要求代理的身份认证，与401类似，但请求者应当使用代理进行授权 */
const StatusCode STATUSCODE_407 	= {407,"Proxy Authentication Required"};
/** 服务器等待客户端发送的请求时间过长，超时 */
const StatusCode STATUSCODE_408 	= {408,"Request Time-out"};
/** 服务器完成客户端的 PUT 请求时可能返回此代码，服务器处理请求时发生了冲突 */
const StatusCode STATUSCODE_409 	= {409,"Conflict"};
/** 客户端请求的资源已经不存在。410不同于404，如果资源以前有现在被永久删除了可使用410代码，网站设计人员可通过301代码指定资源的新位置 */
const StatusCode STATUSCODE_410 	= {410,"Gone"};
/** 服务器无法处理客户端发送的不带Content-Length的请求信息 */
const StatusCode STATUSCODE_411 	= {411,"Length Required"};
/** 客户端请求信息的先决条件错误 */
const StatusCode STATUSCODE_412 	= {412,"Precondition Failed"};
/** 由于请求的实体过大，服务器无法处理，因此拒绝请求。为防止客户端的连续请求，服务器可能会关闭连接。如果只是服务器暂时无法处理，则会包含一个Retry-After的响应信息 */
const StatusCode STATUSCODE_413 	= {413,"Request Entity Too Large"};
/** 请求的URI过长（URI通常为网址），服务器无法处理 */
const StatusCode STATUSCODE_414 	= {414,"Request-URI Too Large"};
/** 服务器无法处理请求附带的媒体格式 */
const StatusCode STATUSCODE_415 	= {415,"Unsupported Media Type"};
/** 客户端请求的范围无效 */
const StatusCode STATUSCODE_416 	= {416,"Requested range not satisfiable"};
/** 服务器无法满足Expect的请求头信息 */
const StatusCode STATUSCODE_417 	= {417,"Expectation Failed"};
/** 服务器内部错误，无法完成请求 */
const StatusCode STATUSCODE_500 	= {500,"Internal Server Error"};
/** 服务器不支持请求的功能，无法完成请求 */
const StatusCode STATUSCODE_501 	= {501,"Not Implemented"};
/** 作为网关或者代理工作的服务器尝试执行请求时，从远程服务器接收到了一个无效的响应 */
const StatusCode STATUSCODE_502 	= {502,"Bad Gateway"};
/** 由于超载或系统维护，服务器暂时的无法处理客户端的请求。延时的长度可包含在服务器的Retry-After头信息中 */
const StatusCode STATUSCODE_503 	= {504,"Service Unavailable"};
/** 充当网关或代理的服务器，未及时从远端服务器获取请求*/
const StatusCode STATUSCODE_504 	= {504,"Gateway Time-out"};
/** 服务器不支持请求的HTTP协议的版本，无法完成处理*/
const StatusCode STATUSCODE_505= {505, 	"HTTP Version not supported"};


const char* MIME_TYPE_AUDIO_BASIC="audio/basic";
const char* MIME_TYPE_AUDIO_MPEG="audio/mpeg";
const char* MIME_TYPE_AUDIO_X_AIFF="audio/x-aiff";
const char* MIME_TYPE_AUDIO_X_WAV="audio/x-wav";
const char* MIME_TYPE_APPLICATION_JAVASCRIPT="application/javascript";
const char* MIME_TYPE_APPLICATION_JAVA="application/java";
const char* MIME_TYPE_APPLICATION_JSON="application/json";
const char* MIME_TYPE_APPLICATION_VNDWAPWMLC="application/vnd.wap.wmlc";
const char* MIME_TYPE_APPLICATION_VNDWAPWMLSCRIPTC="application/vnd.wap.wmlscriptc";
const char* MIME_TYPE_APPLICATION_XML="application/xml";
const char* MIME_TYPE_APPLICATION_XHTMLXML="application/xhtml+xml";
const char* MIME_TYPE_APPLICATION_X_WWWFORMURLENCODED="application/x-www-form-urlencoded";
const char* MIME_TYPE_APPLICATION_X_POSTSCRIPT="application/x-postscript";
const char* MIME_TYPE_APPLICATION_X_CSH="application/x-csh";
const char* MIME_TYPE_APPLICATION_X_SH="application/x-sh";
const char* MIME_TYPE_APPLICATION_X_TCL="application/x-tcl";
const char* MIME_TYPE_APPLICATION_X_TEX="application/x-tex";
const char* MIME_TYPE_APPLICATION_X_TEXINFO="application/x-texinfo";
const char* MIME_TYPE_APPLICATION_X_TROFF="application/x-troff";
const char* MIME_TYPE_APPLICATION_X_TROFFMAN="application/x-troff-man";
const char* MIME_TYPE_APPLICATION_X_TROFFME="application/x-troff-me";
const char* MIME_TYPE_APPLICATION_X_WAISSOURCE="application/x-wais-source";
const char* MIME_TYPE_APPLICATION_X_BCPIO="application/x-bcpio";
const char* MIME_TYPE_APPLICATION_X_CPIO="application/x-cpio";
const char* MIME_TYPE_APPLICATION_X_GTAR="application/x-gtar";
const char* MIME_TYPE_APPLICATION_X_SHAR="application/x-shar";
const char* MIME_TYPE_APPLICATION_X_SV4CPIO="application/x-sv4cpio";
const char* MIME_TYPE_APPLICATION_X_SV4CRC="application/x-sv4crc";
const char* MIME_TYPE_APPLICATION_X_TAR="application/x-tar";
const char* MIME_TYPE_APPLICATION_X_USTAR="application/x-ustar";
const char* MIME_TYPE_APPLICATION_X_DVI="application/x-dvi";
const char* MIME_TYPE_APPLICATION_X_HDF="application/x-hdf";
const char* MIME_TYPE_APPLICATION_X_LATEX="application/x-latex";
const char* MIME_TYPE_APPLICATION_ZIP="application/zip";
const char* MIME_TYPE_APPLICATION_OCTETSTREAM="application/octet-stream";
const char* MIME_TYPE_APPLICATION_ODA="application/oda";
const char* MIME_TYPE_APPLICATION_PDF="application/pdf";
const char* MIME_TYPE_APPLICATION_POSTSCRIPT="application/postscript";
const char* MIME_TYPE_APPLICATION_RTF="application/rtf";
const char* MIME_TYPE_APPLICATION_X_NETCDF="application/x-netcdf";
const char* MIME_TYPE_APPLICATION_X_X509CACERT="application/x-x509-ca-cert";
const char* MIME_TYPE_APPLICATION_X_GZIP="application/x-gzip";
const char* MIME_TYPE_APPLICATION_X_COMPRESS="application/x-compress";
const char* MIME_TYPE_APPLICATION_X_MIF="application/x-mif";
const char* MIME_TYPE_APPLICATION_MAC_BINHEX40="application/mac-binhex40";
const char* MIME_TYPE_IMAGE_BMP="image/bmp";
const char* MIME_TYPE_IMAGE_GIF="image/gif";
const char* MIME_TYPE_IMAGE_IEF="image/ief";
const char* MIME_TYPE_IMAGE_JPEG="image/jpeg";
const char* MIME_TYPE_IMAGE_PNG="image/png";
const char* MIME_TYPE_IMAGE_TIFF="image/tiff";
const char* MIME_TYPE_IMAGE_SVGXML="image/svg+xml";
const char* MIME_TYPE_IMAGE_VNDWAPWBMP="image/vnd.wap.wbmp";
const char* MIME_TYPE_IMAGE_X_CMURASTER="image/x-cmu-raster";
const char* MIME_TYPE_IMAGE_X_PORTABLEANYMAP="image/x-portable-anymap";
const char* MIME_TYPE_IMAGE_X_PORTABLEBITMAP="image/x-portable-bitmap";
const char* MIME_TYPE_IMAGE_X_PORTABLEGRAYMAP="image/x-portable-graymap";
const char* MIME_TYPE_IMAGE_X_PORTABLEPIXMAP="image/x-portable-pixmap";
const char* MIME_TYPE_IMAGE_X_RGB="image/x-rgb";
const char* MIME_TYPE_IMAGE_X_XBITMAP="image/x-xbitmap";
const char* MIME_TYPE_IMAGE_X_XPIXMAP="image/x-xpixmap";
const char* MIME_TYPE_IMAGE_X_XWINDOWDUMP="image/x-xwindowdump";
const char* MIME_TYPE_MULTIPART_FORMDATA="multipart/form-data";
const char* MIME_TYPE_TEXT_CSS="text/css";
const char* MIME_TYPE_TEXT_HTML="text/html";
const char* MIME_TYPE_TEXT_PLAIN="text/plain";
const char* MIME_TYPE_TEXT_RICHTEXT="text/richtext";
const char* MIME_TYPE_TEXT_TABSEPARATEDVALUES="text/tab-separated-values";
const char* MIME_TYPE_TEXT_VNDWAPWML="text/vnd.wap.wml";
const char* MIME_TYPE_TEXT_VNDWAPWMLSCRIPT="text/vnd.wap.wmlscript";
const char* MIME_TYPE_TEXT_XML="text/xml";
const char* MIME_TYPE_TEXT_X_SETEXT="text/x-setext";
const char* MIME_TYPE_VIDEO_MPEG2="video/mpeg2";
const char* MIME_TYPE_VIDEO_QUICKTIME="video/quicktime";
const char* MIME_TYPE_VIDEO_X_MSVIDEO="video/x-msvideo";
const char* MIME_TYPE_VIDEO_X_SGIMOVIE="video/x-sgi-movie";
const char* MIME_TYPE_VIDEO_X_RADSCREENPLAY="video/x-rad-screenplay";
const char* MIME_TYPE_XWORLD_X_VRML="x-world/x-vrml";
}
}
#endif
