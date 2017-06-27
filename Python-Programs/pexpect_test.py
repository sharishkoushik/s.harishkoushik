import pexpect
import argparse
import sys

class SwitchConfig:
    def __init__(self, switch_type, switch_ip, switch_username, switch_password):
        self.switch_type = switch_type
        self.switch_ip = switch_ip
        self.switch_username = switch_username
        self.switch_password = switch_password
	print "password is : ", self.switch_password
    
    def expect(self):
        return self.child.expect(self.switch_type+"#")

    def main(self):
        self.child=pexpect.spawn('ssh %s@%s' %(self.switch_username, self.switch_ip))
        self.child.logfile = sys.stdout
	self.child.expect(self.switch_username+'@'+self.switch_ip+"'s password:")
	self.child.sendline(self.switch_password)
	self.expect()
        #self.child.expect(self.switch_type+'#') ---> Old version
        self.child.sendline('show version')
	self.expect()
        self.child.sendline('quit')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="First Pexpect")
    parser.add_argument("--switch_type", required=False)
    parser.add_argument("--switch_ip", required=True)
    parser.add_argument("--switch_username", required=True)
    parser.add_argument("--switch_password", required=True)
    args = parser.parse_args()
    config = SwitchConfig(args.switch_type, args.switch_ip, args.switch_username, args.switch_password)
    config.main()
