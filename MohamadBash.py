import os
import socket
import getpass

def execute(args):
    pid = os.fork()

    if pid > 0:
        os.waitpid(pid, 0)
    else:
        try:
            os.execvp(args[0], args)
        except Exception as e:
            print(print(e) ,type(e))
            exit()

def headline():
    hline = "\033[96m"+getpass.getuser()+"@"+socket.gethostname()+"\033[00m"+":"+"\033[92m"+os.getcwd()+"\033[00m"+"- "
    return hline


if __name__ == "__main__":
    
    while True:
        args = input(headline()).split()
        if args[0]=="exit":
            exit()
        elif args[0]=="cd":
            try:
                if args[1][0] == '/':
                    addr = args[1]
                else:
                    addr = os.getcwd()+'/'+args[1]
                os.chdir(addr)
            except Exception as e:
                print(print(e) ,type(e))
        elif args[0]=="pwd":
            print(os.getcwd())
        else:
            execute(args)
        
