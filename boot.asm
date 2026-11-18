[org 0x7C00]
mov si, mesaj
yaz:
  lodsb
  or al, al
  jz dur
  mov ah, 0x0E
  int 0x10
  jmp yaz
dur:
  jmp $
mesaj db "Merhaba, bu benim isletim sistemim!", 0
times 510-($-$$) db 0
dw 0xAA55
