#include <string>
#include <iostream>
#include <limits>

using namespace std;

int		fixedSubnetPart(const char *subnetMask)
{
	int dontTouch = 0;
	for (int i = 3; i >= 0; i--)
	{
		if ((int)(unsigned char)subnetMask[i] != 255)
			return (dontTouch);
		dontTouch++;
	}
	return (-1);
}

void	printSubnetRanges(const char *subnet, const char *subnetMask, int remainder)
{
	int	dontTouch = fixedSubnetPart(subnetMask);
	printf("dont tuch = %d\n", dontTouch);
	int	increment = 8 - remainder + (3 - dontTouch) * 8;
	increment = (int)pow(2, increment);
	int part = 0;
	string temp;
	for (int i = 0;  i < dontTouch; i++)
	{
		temp += to_string((int)(unsigned char)subnet[3 - i]);
		temp += ".";
	}
	while (part < 256)
	{
		cout << "valid rang : " << temp << part << " -> " << temp << part + increment - 1 << endl;
		part += increment;
	}
	cout << "how many part will still fix: " << increment << endl;
	cout << "still fix: " << temp << endl;
}

int printBits(const char *bit) {
	int	remainder = 0; // find the increment
    for (int i = 3; i >= 0; i--) {
        for (int k = 7; k >= 0; k--) {
            if (bit[i] & (1 << k))
			{
                cout << "1";
				remainder = 8 - k;
			}
            else
                cout << "0";
        }
        if (i > 0)
            cout << ".";
    }
    cout << endl;
	for (int i = 3; i >= 0; i--)
	{
		printf("%d", (int)(unsigned char)bit[i]);
		if (i > 0) 
			cout << ".";
	}
    cout << endl;
	return (remainder % 8);
}

int main() {
    string input;
    char subnetMask[4];
    char subnet[4];
    char *temp;

    cout << "Welcome to NetPractise_v0.1" << endl << endl;
    cout << "Enter Your Subnet Mask: ";

    while (getline(cin, input)) {
        if (!input.empty())
            break;
        cout << "Enter Your Subnet Mask: ";
    }

    temp = strtok((char *)input.c_str(), ".");
    int i = 3;
    while (temp && i >= 0) {
        subnetMask[i] = atoi(temp);
        i--;
        temp = strtok(NULL, ".");
    }

    int remainder = printBits(subnetMask);
	printf("remainder = %d\n", remainder);

/////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Enter Your Subnet: ";

    while (getline(cin, input)) {
        if (!input.empty())
            break;
        cout << "Enter Your Subnet: ";
    }

    temp = strtok((char *)input.c_str(), ".");
    i = 3;
    while (temp && i >= 0) {
        subnet[i] = atoi(temp);
        i--;
        temp = strtok(NULL, ".");
    }
	printSubnetRanges(subnet, subnetMask, remainder);
    return 0;
}
