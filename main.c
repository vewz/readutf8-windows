#include <stdio.h>
#include <windows.h>

int main(void) {
  WCHAR buffer[80];
  char utf8_decoded[80];
  DWORD read_len;
  int decoded_len;

  memset(buffer, 80, sizeof(WCHAR));
  memset(utf8_decoded, 80, sizeof(char));

  printf("入力>>");
  fflush(stdout);

  if (!ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), buffer, 80, &read_len, NULL)) {
    printf("Failed to read stdin\n");
    return 1;
  }
  decoded_len = WideCharToMultiByte(CP_UTF8, 0, buffer, read_len, utf8_decoded, 80, NULL, NULL);
  if (!decoded_len) {
    printf("Failed to decode into UTF-8\n");
    return 1;
  }
  printf("input is '%s'", utf8_decoded);
  return 0;
}
