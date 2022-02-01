from header import *

class LeNet5(torch.nn.Module):
    def __init__(self):
        super(LeNet5, self).__init__()
        self.conv1 = torch.nn.Conv2d(in_channels=3, out_channels=5, kernel_size=5, padding=2)
        self.act1 = torch.nn.Tanh()
        self.pool1 = torch.nn.AvgPool2d(kernel_size=8, stride=4)

        self.conv2 = torch.nn.Conv2d(in_channels=5, out_channels=10, kernel_size=5, padding=2)
        self.act2 = torch.nn.Tanh()
        self.pool2 = torch.nn.AvgPool2d(kernel_size=8, stride=4)

        self.conv3=torch.nn.Conv2d(in_channels=10, out_channels=25, kernel_size=5,padding=2)
        self.act3 = torch.nn.Tanh()
        self.pool3 = torch.nn.AvgPool2d(kernel_size=6, stride=3)


        self.fc1 = torch.nn.Linear(5 * 5 * 25, 120) #30 хуже 20 похоже 15 чуть хуже
        self.act3 = torch.nn.Tanh()

        self.fc2 = torch.nn.Linear(120, 51)
        self.act4 = torch.nn.Tanh()

    def forward(self, x):
        #print(x.shape)
        x = self.conv1(x)
        x = self.act1(x)
        x = self.pool1(x)
        #print(x.shape)
        x = self.conv2(x)
        x = self.act2(x)
        x = self.pool2(x)
        #print(x.shape)
        x = self.conv3(x)
        x = self.act3(x)
        x = self.pool3(x)

        #print(x.shape)
        x = x.view(x.size(0), x.size(1) * x.size(2) * x.size(3))

        x = self.fc1(x)
        x = self.act3(x)
        x = self.fc2(x)
        x = self.act4(x)

        #(x.shape)
        return x


