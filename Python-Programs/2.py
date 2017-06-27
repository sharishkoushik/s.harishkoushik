import paramiko
import os 
class ssh_connection:
    "ssh class"
    def __init__ (self):
        return
    #
    def __str__(self):
        return "ssh class"

    def open_ssh_connection(self, cNodeIP):
        self.ssh_conn = paramiko.SSHClient()
        self.ssh_conn.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        try:
            self.ssh_conn.connect("100.67.193.16", username='root',
	    password='Dell1234')
        except:
            print "Cannot ssh into " + cNodeIP
            return False

        print "SSH connection successful with " + str(cNodeIP)
        return True
    #
    def execute (self, cmd):
        return self.ssh_conn.exec_command (cmd)
    #
    def close_ssh_connection(self):
        self.ssh_conn.close()

myssh = ssh_connection()
myssh.open_ssh_connection("100.67.193.16")
ssh_stdin,ssh_stdout,ssh_stderr = myssh.execute('ls')
sshout = ssh_stdout.readlines()
myssh.close_ssh_connection()
print myssh.__doc__
print myssh.__str__
#print myssh.__doc__

#ssh = paramiko.SSHClient()
#ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
#ssh.connect("100.67.193.16", username="root", password="Dell1234")
#sshin, sshout, ssherr = ssh.exec_command("ls")
#out = sshout.readlines()
#print out
