/*#pragma once
#include <curl/curl.h> 
#include <string>
#include <cstring>
using namespace std;
CURLcode login() {
	CURL *hnd = curl_easy_init();

	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnd, CURLOPT_URL, "https://api.shisanshui.rtxux.xyz/auth/login");

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "content-type: application/json");
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

	curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\"username\":\"Seast\",\"password\":\"654321\"}");

	CURLcode ret = curl_easy_perform(hnd);
	return ret; 
}
char str[105];
CURLcode login_check(string token) {
	CURL *hnd = curl_easy_init();

	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
	curl_easy_setopt(hnd, CURLOPT_URL, "https://api.shisanshui.rtxux.xyz/auth/validate");

	struct curl_slist *headers = NULL;
	string s = "x-auth-token: " + token;
	int m = 0;
	for (int i = 0; i < (int)s.size(); i++)
		str[m++] = s[i];
	headers = curl_slist_append(headers, str);
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

	CURLcode ret = curl_easy_perform(hnd);
	return ret;
}

*/