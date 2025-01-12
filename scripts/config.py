config.bind('xs', 'config-cycle statusbar.show always never')
config.bind('xt', 'config-cycle tabs.show always never')
config.bind('xx', 'config-cycle tabs.show always never;; config-cycle statusbar.show always never')
config.bind('so', 'spawn --userscript open_selection.sh')
config.bind('sO', 'spawn --userscript open_selection_new_window.sh')
config.bind('ao', 'set-cmd-text -s :spawn --userscript find_definition.sh')
config.bind('ww', 'open -w')
c.url.default_page = "https://www.google.com"
c.url.searchengines =  {"DEFAULT" : "https://www.google.com/search?hl=en&q={}"}
c.url.start_pages = ["https://www.google.com"]
#c.auto_save.session = True
config.load_autoconfig(False)
# point this to where you cloned qutenyan
config.source('qutenyan/nyan.py')
