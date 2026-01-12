namespace ModbusMaster
{
    partial class Form1
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.comboBox_PortName = new System.Windows.Forms.ComboBox();
            this.button_Connect = new System.Windows.Forms.Button();
            this.checkBox_Run = new System.Windows.Forms.CheckBox();
            this.checkBox_Lock = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // comboBox_PortName
            // 
            this.comboBox_PortName.FormattingEnabled = true;
            this.comboBox_PortName.Location = new System.Drawing.Point(12, 12);
            this.comboBox_PortName.Name = "comboBox_PortName";
            this.comboBox_PortName.Size = new System.Drawing.Size(121, 20);
            this.comboBox_PortName.TabIndex = 0;
            // 
            // button_Connect
            // 
            this.button_Connect.Location = new System.Drawing.Point(139, 9);
            this.button_Connect.Name = "button_Connect";
            this.button_Connect.Size = new System.Drawing.Size(75, 23);
            this.button_Connect.TabIndex = 1;
            this.button_Connect.Text = "Connect";
            this.button_Connect.UseVisualStyleBackColor = true;
            this.button_Connect.Click += new System.EventHandler(this.button_Connect_Click);
            // 
            // checkBox_Run
            // 
            this.checkBox_Run.AutoSize = true;
            this.checkBox_Run.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.checkBox_Run.Location = new System.Drawing.Point(318, 18);
            this.checkBox_Run.Name = "checkBox_Run";
            this.checkBox_Run.Size = new System.Drawing.Size(44, 16);
            this.checkBox_Run.TabIndex = 8;
            this.checkBox_Run.Text = "Run";
            this.checkBox_Run.UseVisualStyleBackColor = true;
            this.checkBox_Run.CheckedChanged += new System.EventHandler(this.checkBox_Run_CheckedChanged);
            // 
            // checkBox_Lock
            // 
            this.checkBox_Lock.AutoSize = true;
            this.checkBox_Lock.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.checkBox_Lock.Location = new System.Drawing.Point(318, 40);
            this.checkBox_Lock.Name = "checkBox_Lock";
            this.checkBox_Lock.Size = new System.Drawing.Size(48, 16);
            this.checkBox_Lock.TabIndex = 8;
            this.checkBox_Lock.Text = "Lock";
            this.checkBox_Lock.UseVisualStyleBackColor = true;
            this.checkBox_Lock.CheckedChanged += new System.EventHandler(this.checkBox_Free_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(567, 401);
            this.Controls.Add(this.checkBox_Lock);
            this.Controls.Add(this.checkBox_Run);
            this.Controls.Add(this.button_Connect);
            this.Controls.Add(this.comboBox_PortName);
            this.Name = "Form1";
            this.Text = "ModbusMaster";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBox_PortName;
        private System.Windows.Forms.Button button_Connect;
        private System.Windows.Forms.CheckBox checkBox_Run;
        private System.Windows.Forms.CheckBox checkBox_Lock;
    }
}

