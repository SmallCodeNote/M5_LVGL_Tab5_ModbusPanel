using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

using System.Buffers.Binary;

using Microsoft.Extensions.Logging;
using FluentModbus;

namespace ModbusMaster
{
    public partial class Form1 : Form
    {
        private SerialPort serialPort;
        ModbusRtuClient client;
        //string clientPort = "COM7";

        byte unitIdentifier = 0x02;

        byte[] getBigEndian(int value)
        {
            byte[] buffer = new byte[2];
            BinaryPrimitives.WriteUInt16BigEndian(buffer, (ushort)value);
            return buffer.ToArray();

        }

        byte[] getBigEndian(TextBox textBox)
        {
            ushort value = 0;

            ushort.TryParse(textBox.Text, out value);

            byte[] buffer = new byte[2];
            BinaryPrimitives.WriteUInt16BigEndian(buffer, (ushort)value);
            return buffer.ToArray();

        }


        public Form1()
        {
            InitializeComponent();
            LoadSerialPorts();
        }

        private void LoadSerialPorts()
        {
            comboBox_PortName.Items.Clear();
            string[] ports = SerialPort.GetPortNames();
            comboBox_PortName.Items.AddRange(ports);

            if (ports.Length > 0)
                comboBox_PortName.SelectedIndex = 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {



        }

        private void button_Connect_Click(object sender, EventArgs e)
        {
            string portName = comboBox_PortName.SelectedItem.ToString();

            client = new ModbusRtuClient()
            {
                BaudRate = 9600,
                Parity = Parity.Even,
                StopBits = StopBits.One
            };

            client.Connect(portName);

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (serialPort != null && serialPort.IsOpen)
                serialPort.Close();
        }

        private void button_Test_Click(object sender, EventArgs e)
        {
            string portName = "COM7";
            SerialPort sp = new SerialPort(portName)
            {
                BaudRate = 9600,
                //BaudRate = 115200,
                DataBits = 8,
                Parity = Parity.Even,   //  (SERIAL_8E1)
                StopBits = StopBits.One
            };

            sp.Open();
            Console.WriteLine("Opened " + portName);

            // --- [1]  ---
            // SlaveID=2, Function=3, StartAddr=0x0000, Quantity=0x000A
            byte[] request = new byte[] { 0x02, 0x03, 0x00, 0x00, 0x00, 0x0A, 0xC5, 0xFE };
            sp.Write(request, 0, request.Length);

            Thread.Sleep(250);
            Console.WriteLine(">: " + BitConverter.ToString(request));

            // --- [2]  ---
            Console.Write("<: ");
            List<int> buffsp = new List<int>();
            while (sp.BytesToRead > 0)
            {
                int b = sp.ReadByte();
                buffsp.Add(b);
                //Console.Write($"{b:X2} ");

                Thread.Sleep(10);
            }

            string result = string.Join("-", buffsp.Select(x => x.ToString("X2")));
            Console.WriteLine(result);

            sp.Close();
        }

        private void checkBox_Run_CheckedChanged(object sender, EventArgs e)
        {
            if (client == null || !client.IsConnected) return;
            byte[] val = checkBox_Run.Checked ? getBigEndian(1) : getBigEndian(0);
            client.WriteSingleRegister(unitIdentifier, (int)HoldingRegister.run_flag, val);

        }

        private void checkBox_Free_CheckedChanged(object sender, EventArgs e)
        {
            if (client == null || !client.IsConnected) return;
            byte[] val = checkBox_Lock.Checked ? getBigEndian(1) : getBigEndian(0);
            client.WriteSingleRegister(unitIdentifier, (int)HoldingRegister.lock_flag, val);

        }

        enum HoldingRegister : ushort
        {
            lock_flag = 0,
            run_flag,
            display_pv_1,
            display_pv_2,
            display_pv_3,
            display_pv_4,
            display_pv_5,
            run_progress_max,
            run_progress,
            run_sv_1,
            run_sv_2,
            run_sv_3,
            run_sv_4,
            run_sv_5,
            run_sv_select,
            run_sv_status,
            unit_int_sv_1,
            unit_int_sv_2,
            unit_int_sv_3,
            unit_int_sv_4,
            unit_int_sv_5,
            unit_pv_1,
            unit_pv_2,
            unit_pv_3,
            unit_pv_4,
            unit_pv_5,
            chart_max_1,
            chart_max_2,
            chart_max_3,
            chart_max_4,
            chart_max_5,
            chart_min_1,
            chart_min_2,
            chart_min_3,
            chart_min_4,
            chart_min_5,
            REG_COUNT
        }
    }
}
