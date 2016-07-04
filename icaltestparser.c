/* -*- Mode: C -*-
  ======================================================================
  FILE: icaltestparser.c
  CREATOR: eric 20 June 1999
  
  $Id: icaltestparser.c,v 1.4 2008-01-02 20:07:45 dothebart Exp $
  $Locker:  $
    
 The contents of this file are subject to the Mozilla Public License
 Version 1.0 (the "License"); you may not use this file except in
 compliance with the License. You may obtain a copy of the License at
 http://www.mozilla.org/MPL/
 
 Software distributed under the License is distributed on an "AS IS"
 basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 the License for the specific language governing rights and
 limitations under the License.

  The original author is Eric Busboom
  The original code is icaltestparser.c

 
 (C) COPYRIGHT 1999 The Software Studio. 
 http://www.softwarestudio.org

 ======================================================================*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "libical/ical.h"

#include <stdlib.h>


char* read_stream(char *s, size_t size, void *d)
{
  char *c = fgets(s,size, (FILE*)d);

  return c;

}



int main(int argc, char* argv[])
{
    char* line; 
    FILE* stream;
    icalcomponent *c; 
    icalparser *parser = icalparser_new();



long lSize;
char *buffer;
//while (__AFL_LOOP(1000)){
    stream = fopen(argv[1],"r");
fseek( stream , 0L , SEEK_END);
lSize = ftell( stream );
rewind( stream );

/* allocate memory for entire content */
buffer = calloc( 1, lSize+1 );
if( !buffer ) fclose(stream),fputs("memory alloc fails",stderr),exit(1);

/* copy the file into the buffer */
if( 1!=fread( buffer , lSize, 1 , stream) )
  fclose(stream),free(buffer),fputs("entire read fails",stderr),exit(1);

icalparser_parse_string(buffer);

//    icalparser_set_gen_data(parser,stream);

  //  do{
  // 
//	line = icalparser_get_line(parser,read_stream);

//	c = icalparser_add_line(parser,line);

//
//	if (c != 0){
	    /*icalcomponent_convert_errors(c);*/
//	    printf("%s",icalcomponent_as_ical_string(c));
//	    printf("\n---------------\n");
//	    icalcomponent_free(c);
//	}

  //  } while ( line != 0);
//}
    return 0;
 }
