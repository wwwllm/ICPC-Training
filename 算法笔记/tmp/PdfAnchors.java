import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import org.apache.pdfbox.Loader;
import org.apache.pdfbox.cos.COSArray;
import org.apache.pdfbox.cos.COSBase;
import org.apache.pdfbox.cos.COSDictionary;
import org.apache.pdfbox.cos.COSName;
import org.apache.pdfbox.cos.COSString;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.interactive.documentnavigation.destination.PDDestination;
import org.apache.pdfbox.pdmodel.interactive.documentnavigation.destination.PDPageDestination;

public final class PdfAnchors {
    private static void visit(COSDictionary node, List<COSDictionary> pages) {
        COSArray names = (COSArray) node.getDictionaryObject(COSName.NAMES);
        if (names != null) for (int i = 0; i + 1 < names.size(); i += 2) {
            String key = ((COSString) names.getObject(i)).getString();
            COSBase value = names.getObject(i + 1);
            COSArray dest = value instanceof COSArray ? (COSArray) value : null;
            if (dest == null && value instanceof COSDictionary) dest = (COSArray) ((COSDictionary) value).getDictionaryObject(COSName.D);
            if (dest == null || dest.size() == 0) continue;
            COSBase page = dest.getObject(0);
            for (int p = 0; p < pages.size(); p++) if (pages.get(p).equals(page)) {
                System.out.println(key + "\t" + (p + 1));
                break;
            }
        }
        COSArray kids = (COSArray) node.getDictionaryObject(COSName.KIDS);
        if (kids != null) for (COSBase kid : kids) visit((COSDictionary) kid, pages);
    }

    public static void main(String[] args) throws Exception {
        try (PDDocument doc = Loader.loadPDF(new File(args[0]))) {
            List<COSDictionary> pages = new ArrayList<>();
            for (PDPage page : doc.getPages()) pages.add(page.getCOSObject());
            COSDictionary dests = (COSDictionary) doc.getDocumentCatalog().getCOSObject().getDictionaryObject(COSName.DESTS);
            if (dests != null) {
                for (Map.Entry<COSName, COSBase> entry : dests.entrySet()) {
                    String key = entry.getKey().getName();
                    COSArray dest = entry.getValue() instanceof COSArray ? (COSArray) entry.getValue() : null;
                    if (dest == null || dest.size() == 0) continue;
                    PDDestination destination = PDDestination.create(dest);
                    if (destination instanceof PDPageDestination) {
                        System.out.println(key + "\t" + (((PDPageDestination) destination).retrievePageNumber() + 1));
                    }
                }
            }
        }
    }
}
