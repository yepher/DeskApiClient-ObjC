//
//  DSAPICase.h
//  DeskAPIClient
//
//  Created by Desk.com on 9/24/13.
//  Copyright (c) 2015, Salesforce.com, Inc.
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided
//  that the following conditions are met:
//  
//     Redistributions of source code must retain the above copyright notice, this list of conditions and the
//     following disclaimer.
//  
//     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
//     the following disclaimer in the documentation and/or other materials provided with the distribution.
//  
//     Neither the name of Salesforce.com, Inc. nor the names of its contributors may be used to endorse or
//     promote products derived from this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
//  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
//  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
//  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//

#import "DSAPIResource.h"
@class DSAPINote;
@class DSAPIInteraction;
@class DSAPIAttachment;

@interface DSAPICase : DSAPIResource


#pragma mark - Class Methods

/**
 Lists cases by calling a GET to the /api/v2/cases endpoint of the Desk.com API.=
 
 @param parameters The querystring parameters to be sent with the GET request (including 'embed' to embed a resource in the response, and 'page' and 'per_page' for pagination).
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.=
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
+ (void)listCasesWithParameters:(NSDictionary *)parameters
                        success:(DSAPIPageSuccessBlock)success
                        failure:(DSAPIFailureBlock)failure;

/**
 Lists cases by calling a GET to the /api/v2/cases endpoint of the Desk.com API. Supports ETag caching
 
 @param parameters The querystring parameters to be sent with the GET request (including 'embed' to embed a resource in the response, and 'page' and 'per_page' for pagination).
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
+ (void)listCasesWithParameters:(NSDictionary *)parameters
                        success:(DSAPIPageSuccessBlock)success
                    notModified:(DSAPIPageSuccessBlock)notModified
                        failure:(DSAPIFailureBlock)failure;


/**
 Searches cases by calling a GET to the /api/v2/cases/search endpoint of the Desk.com API.
 
 @param parameters The querystring parameters to be sent with the GET request (including 'embed' to embed a resource in the response, and 'page' and 'per_page' for pagination).
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
+ (void)searchCasesWithParameters:(NSDictionary *)parameters
                          success:(DSAPIPageSuccessBlock)success
                          failure:(DSAPIFailureBlock)failure;


/**
 Searches cases by calling a GET to the /api/v2/cases/search endpoint of the Desk.com API. Supports ETag caching.
 
 @param parameters The querystring parameters to be sent with the GET request (including 'embed' to embed a resource in the response, and 'page' and 'per_page' for pagination).
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
+ (void)searchCasesWithParameters:(NSDictionary *)parameters
                          success:(DSAPIPageSuccessBlock)success
                      notModified:(DSAPIPageSuccessBlock)notModified
                          failure:(DSAPIFailureBlock)failure;


/**
 Creates a case by calling a POST to the /api/v2/cases endpoint of the Desk.com API.
 
 @param caseDict A dictionary defining the new case.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the new case (`DSAPICase`) created and returned by the POST request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
+ (void)createCase:(NSDictionary *)caseDict
           success:(void (^)(DSAPICase *newCase))success
           failure:(DSAPIFailureBlock)failure;


/**
 Shows a case by calling a GET to the /api/v2/cases/:id endpoint of the Desk.com API.
 
 @param caseId The unique id for the case to show
 @param parameters The querystring parameters to be sent with the GET request (including 'embed' to embed a resource in the response)
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the case (`DSAPICase`) created and returned by the POST request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
+ (void)showById:(NSNumber *)caseId
      parameters:(NSDictionary *)parameters
         success:(void (^)(DSAPICase *theCase))success
         failure:(DSAPIFailureBlock)failure;


#pragma mark - Instance Methods

/**
 Shows an individual case by calling a GET to the case's "self" link.
 
 @param parameters The querystring parameters to be sent with the GET request (including 'embed' to embed a resource in the response)
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the case (`DSAPICase`) returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)showWithParameters:(NSDictionary *)parameters
                   success:(void (^)(DSAPICase *theCase))success
                   failure:(DSAPIFailureBlock)failure;


/**
 Updates a case by calling a PATCH to the case's "self" link.
 
 @param dictionary A dictionary defining the updates to the case.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the updated case (`DSAPICase`) returned by the PATCH request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)updateWithDictionary:(NSDictionary *)dictionary
                     success:(void (^)(DSAPICase *))success
                     failure:(DSAPIFailureBlock)failure;


#pragma mark - Message, Replies, and Draft

/**
 Shows the original message for an individual case by calling a GET to the case's "message" link.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the message (`DSAPIInteraction`) returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)showMessageWithParameters:(NSDictionary *)parameters
                          success:(void (^)(DSAPIInteraction *message))success
                          failure:(DSAPIFailureBlock)failure;


/**
 Lists the replies for an individual case by calling a GET to the case's "replies" link.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listRepliesWithParameters:(NSDictionary *)parameters
                          success:(DSAPIPageSuccessBlock)success
                          failure:(DSAPIFailureBlock)failure;


/**
 Lists the replies for an individual case by calling a GET to the case's "replies" link. Supports ETag caching.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listRepliesWithParameters:(NSDictionary *)parameters
                          success:(DSAPIPageSuccessBlock)success
                      notModified:(DSAPIPageSuccessBlock)notModified
                          failure:(DSAPIFailureBlock)failure;


/**
 Lists the conversation (message, replies, notes) for an individual case by calling a GET to the case's "feed" link.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listFeedWithParameters:(NSDictionary *)parameters
                       success:(DSAPIPageSuccessBlock)success
                       failure:(DSAPIFailureBlock)failure;


/**
 Lists the conversation (message, replies, notes) for an individual case by calling a GET to the case's "feed" link. Supports ETag caching.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listFeedWithParameters:(NSDictionary *)parameters
                       success:(DSAPIPageSuccessBlock)success
                   notModified:(DSAPIPageSuccessBlock)notModified
                       failure:(DSAPIFailureBlock)failure;


/**
 Creates a reply for a case by calling a POST to the case's "replies" link.
 
 @param replyDict A dictionary defining the new reply.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the new reply (`DSAPIInteraction`) created and returned by the POST request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)createReply:(NSDictionary *)replyDict
            success:(void (^)(DSAPIInteraction *newReply))success
            failure:(DSAPIFailureBlock)failure;


/**
 Creates a draft reply for a case by calling a POST to the case's "draft" link.
 
 @param draftDict A dictionary defining the new draft reply.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the new reply draft (`DSAPIInteraction`) created and returned by the POST request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)createDraft:(NSDictionary *)draftDict
            success:(void (^)(DSAPIInteraction *newDraft))success
            failure:(DSAPIFailureBlock)failure;

/**
 Shows the original message for an individual case by calling a GET to the case's "draft" link.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the draft (`DSAPIInteraction`) returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)showDraftWithParameters:(NSDictionary *)parameters
                        success:(void (^)(DSAPIInteraction *draft))success
                        failure:(DSAPIFailureBlock)failure;


#pragma mark - Notes

/**
 Lists the notes for an individual case by calling a GET to the case's "notes" link.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listNotesWithParameters:(NSDictionary *)parameters
                        success:(DSAPIPageSuccessBlock)success
                        failure:(DSAPIFailureBlock)failure;


/**
 Lists the notes for an individual case by calling a GET to the case's "notes" link. Supports ETag caching.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listNotesWithParameters:(NSDictionary *)parameters
                        success:(DSAPIPageSuccessBlock)success
                    notModified:(DSAPIPageSuccessBlock)notModified
                        failure:(DSAPIFailureBlock)failure;


/**
 Creates a note for a case by calling a POST to the case's "notes" link.
 
 @param noteDict A dictionary defining the new note.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the new note (`DSAPINote`) created and returned by the POST request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)createNote:(NSDictionary *)noteDict
            success:(void (^)(DSAPINote *newNote))success
           failure:(DSAPIFailureBlock)failure;


#pragma mark - Attachments

/**
 Lists the attachments for an individual case by calling a GET to the case's "attachments" link.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listAttachmentsWithParameters:(NSDictionary *)parameters
                              success:(DSAPIPageSuccessBlock)success
                              failure:(DSAPIFailureBlock)failure;

/**
 Lists the attachments for an individual case by calling a GET to the case's "attachments" link. Supports ETag caching.
 
 @param parameters The querystring parameters to be sent with the GET request
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)listAttachmentsWithParameters:(NSDictionary *)parameters
                              success:(DSAPIPageSuccessBlock)success
                          notModified:(DSAPIPageSuccessBlock)notModified
                              failure:(DSAPIFailureBlock)failure;


/**
 Creates an attachment for a case by calling a POST to the case's "attachments" link (or, if that is nil, to the case's "self" link appended with the string "/attachments").
 
 @param attachmentDict A dictionary defining the new attachment.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the new attachment (`DSAPIAttachment`) created and returned by the POST request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)createAttachment:(NSDictionary *)attachmentDict
                 success:(void (^)(DSAPIAttachment *newAttachment))success
                 failure:(DSAPIFailureBlock)failure;

/**
 Shows history for a case by calling a GET to the case's "self" link with "/history" appended.
 
 @param success A block object to be executed when the task finishes successfully.  This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)historyWithBlock:(DSAPIPageSuccessBlock)success
                 failure:(DSAPIFailureBlock)failure;

/**
 Shows history for a case by calling a GET to the case's "self" link with "/history" appended. Supports ETag caching.
 
 @param success A block object to be executed when the task finishes successfully.  This block has no return value and takes one argument: the page (`DSAPIPage`) of resources returned by the GET request.
 @param notModified A block object to be executed if the web service returns a response of not modified (HTTP status code 304). This is called when the response at this endpoint hasn't changed since the last request (via ETags). This block has no return value and takes one argument: a page (`DSAPIPage`) whose notModified property is set to YES.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)historyWithBlock:(DSAPIPageSuccessBlock)success
             notModified:(DSAPIPageSuccessBlock)notModified
                 failure:(DSAPIFailureBlock)failure;

#pragma mark - Macros

/**
 Previews the application of a list of macros by calling a POST to the case's self link with "/macros/preview" appended.
 
 @param success A block object to be executed when the task finishes successfully.  This block has no return value and takes one argument: the page (`DSAPIPage`) containing embedded resources for the objects affected.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes two arguments: the `NSHTTPURLResponse` from the server, and an `NSError` describing the network or parsing error that occurred.
 */
- (void)previewMacros:(NSArray *)macros
              success:(DSAPIPageSuccessBlock)success
              failure:(DSAPIFailureBlock)failure;

@end
