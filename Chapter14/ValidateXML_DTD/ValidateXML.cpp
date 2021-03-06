#using <system.xml.dll>

using namespace System;
using namespace System::Xml;
using namespace System::Xml::Schema;

ref class ValidateXML
{
public:
    ValidateXML(String ^filename)
    {
        XmlReader ^vreader;
        try
        {
            XmlReaderSettings ^settings = gcnew XmlReaderSettings();
            settings->ProhibitDtd = false;
            settings->ValidationType = ValidationType::DTD;
            vreader = XmlReader::Create(filename, settings);
     
            while(vreader->Read())
            {
                // ... Process nodes just like XmlTextReader()
            }
            Console::WriteLine("Finished Processing");
        }
        catch (Exception ^e)
        {
            Console::WriteLine(e->Message);
        }
        finally
        {
            if (vreader->ReadState != ReadState::Closed)
            {
                vreader->Close();
            }
        }
    }
};

void main()
{
	Console::WriteLine("Bad Monsters file");
	Console::WriteLine("-----------------");
    gcnew ValidateXML("BadMonsters.xml");

	Console::WriteLine("\nGood Monsters file");
	Console::WriteLine("------------------");
	// Note this is a custom Monsters.xml because it needs:
	// <!DOCTYPE MonsterList SYSTEM "Monsters.dtd">
    // added to it for validation
    gcnew ValidateXML("Monsters.xml"); 
}
