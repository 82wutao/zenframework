#ifndef __ZEN_FRAMEWORK_API_HPP
#define __ZEN_FRAMEWORK_API_HPP

#include "zen/constants.hpp"
using namespace zen::constants;

namespace zen{

    namespace http{
        char* url_encode(char*);
        char* url_decode(char*);
    }

    namespace framework{
        class Http_Request_Form{
            enum FORM_CONTENT_TYPE{
                APPLICATION_x_www_form_urlencoded,
                MULTIPART_form_data,
                APPLICATION_json,
                TEXT_xml,};
        public:
            virtual Http_Request_Form::FORM_CONTENT_TYPE form_content_type() =0;
            virtual char* get_form_parameter() = 0;
            virtual char** get_form_parameters(int*) = 0;

            virtual bool has_more_part() = 0;
            virtual bool is_file_part() = 0;
            virtual char* file_name() =0;
            virtual int file_read(void* ,int,int)=0;

            virtual bool is_data_part() = 0;
            virtual char* data_name() = 0;
            virtual char* data_value() = 0;

            virtual char* as_text(int*) = 0;

            virtual char* get_charset() = 0;
        };


        class Http_Request{
        public:
            virtual char* get_method() = 0;
            virtual char* get_path() = 0;
            virtual char* get_schema() = 0;
            virtual char* get_version() = 0;

            virtual char* get_query_parameter() = 0;
            virtual char** get_query_parameters(int*) = 0;


            virtual char* get_head(char*) = 0;

            virtual int body_as_form(Http_Request_Form*);
            virtual int read_from_body(void*,int,int) = 0;
        };

        class Http_Reponse{
        public:
            virtual void  set_head(const char*,char*) =0;
            virtual void  set_schema(char*)=0;
            virtual void  set_version(char*)=0;
            virtual void  set_statuscode(constants::StatusCode*)=0;
            virtual int   write_to_body(void*,int,int)=0;
        };


        struct request_context{
            // TODO pid pgroup
            // TODO thread
            // TODO app name,
            // TODO doc root dir
        };

        using Controller =char* (*)(request_context*, Http_Request*,Http_Reponse*);


        using next = void (*)();
        using Middleware = void (*)(request_context*, Http_Request*,Http_Reponse*,next);

        using http_connection = int;
        using root_interface = void (*)(http_connection);
    }
};

#endif
