import pexpect
import argparse
import sys

class SwitchConfig(object):
    def __init__(self, switch_type, switch_ip, switch_username, switch_password):
        self.switch_type = switch_type
        self.switch_ip = switch_ip
        self.switch_username = switch_username
        self.switch_password = switch_password

class pexpect_connection(SwitchConfig): 
    def __init__(self, switch_type, switch_ip, switch_username, switch_password):
	super(pexpect_connection, self).__init__(switch_type, switch_ip, switch_username, switch_password)
	#SwitchConfig.__init__(self, switch_type, switch_ip, switch_username, switch_password)
        #super().__init__(switch_type,switch_ip,swith_username, switch_password)
        return
    
    def expect(self):
        return self.child.expect(self.switch_type+"#")

    def open_conn(self):
        self.child=pexpect.spawn('ssh %s@%s' %(self.switch_username, self.switch_ip))
        self.child.logfile = sys.stdout
	self.child.expect(self.switch_username+'@'+self.switch_ip+"'s password:")
	self.child.sendline(self.switch_password)
	self.expect()
    
    def execute(self, cmd):
	#self.expect()
        self.child.sendline(cmd)
	self.expect()
        self.child.logfile = sys.stdout
        #self.child.sendline()

    def close_conn(self):
        return sel.child.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="First Pexpect")
    parser.add_argument("--switch_type", required=False)
    parser.add_argument("--switch_ip", required=True)
    parser.add_argument("--switch_username", required=True)
    parser.add_argument("--switch_password", required=True)
    args = parser.parse_args()
    pcon = pexpect_connection(args.switch_type, args.switch_ip, args.switch_username, args.switch_password)
    pcon.open_conn()
    pcon.execute("show version")
    pcon.execute("show interfaces managementethernet 1/1")
    pcon.close_conn

