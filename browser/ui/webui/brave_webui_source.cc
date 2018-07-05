/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/webui/brave_webui_source.h"

#include <map>

#include "components/grit/brave_components_resources.h"
#include "content/public/browser/web_ui_data_source.h"

namespace {

struct WebUISimpleItem {
  const char* name;
  int id;
};

void AddLocalizedStringsBulk(content::WebUIDataSource* html_source,
                             const std::vector<WebUISimpleItem>& simple_items) {
  for (size_t i = 0; i < simple_items.size(); i++) {
    html_source->AddLocalizedString(simple_items[i].name,
                                    simple_items[i].id);
  }
}

void AddResourcePaths(content::WebUIDataSource* html_source,
                      const std::vector<WebUISimpleItem>& simple_items) {
  for (size_t i = 0; i < simple_items.size(); i++) {
    html_source->AddResourcePath(simple_items[i].name,
                                 simple_items[i].id);
  }
}

}  // namespace

void CustomizeWebUIHTMLSource(const std::string &name, content::WebUIDataSource* source) {
  static std::map<std::string, std::vector<WebUISimpleItem> > resources = {
    {
      std::string("newtab"), {
        { "af7ae505a9eed503f8b8e6982036873e.woff2", IDR_BRAVE_COMMON_FONT_AWESOME_1 },
        { "fee66e712a8a08eef5805a46892932ad.woff", IDR_BRAVE_COMMON_FONT_AWESOME_2 },
        { "b06871f281fee6b241d60582ae9369b9.ttf", IDR_BRAVE_COMMON_FONT_AWESOME_3 },

        // New private tab requires Poppins 200 and 400
        // Other variants not added as they're under 10kb size and thus inlined by webpack
        { "1ff8e6c958ca4fa6d8e8680f32cddd0d.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_200_NORMAL_DEVANAGARI },
        { "8a06c170adbf19e0dffcbe868719e6ce.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_400_NORMAL_DEVANAGARI },

        { "img/toolbar/menu_btn.svg", IDR_BRAVE_COMMON_TOOLBAR_IMG },
        // Hash path is the MD5 of the file contents, webpack image loader does this
        { "fd85070af5114d6ac462c466e78448e4.svg", IDR_BRAVE_NEW_TAB_IMG1 },
        { "314e7529efec41c8867019815f4d8dad.svg", IDR_BRAVE_NEW_TAB_IMG4 },
        { "6c337c63662ee0ba4e57f6f8156d69ce.svg", IDR_BRAVE_NEW_TAB_IMG2 },
        { "50cc52a4f1743ea74a21da996fe44272.jpg", IDR_BRAVE_NEW_TAB_IMG14 },
        { "b6dd4b1292cfd4470e58486c56ad0832.svg", IDR_BRAVE_NEW_TAB_PRIVATE_ICON }
      }
    }, {
      std::string("welcome"), {
      }
    }, {
      std::string("rewards"), {
      }
    }, {
      std::string("adblock"), {
      }
    }
  };
  AddResourcePaths(source, resources[name]);

  static std::map<std::string, std::vector<WebUISimpleItem> > localized_strings = {
    {
      std::string("newtab"), {
        { "adsBlocked", IDS_BRAVE_NEW_TAB_TOTAL_ADS_BLOCKED },
        { "trackersBlocked", IDS_BRAVE_NEW_TAB_TOTAL_TRACKERS_BLOCKED },
        { "httpsUpgraded", IDS_BRAVE_NEW_TAB_TOTAL_HTTPS_UPGRADES },
        { "estimatedTimeSaved", IDS_BRAVE_NEW_TAB_TOTAL_TIME_SAVED },
        { "thumbRemoved", IDS_BRAVE_NEW_TAB_THUMB_REMOVED },
        { "undoRemoved", IDS_BRAVE_NEW_TAB_UNDO_REMOVED },
        { "restoreAll", IDS_BRAVE_NEW_TAB_RESTORE_ALL },
        { "second", IDS_BRAVE_NEW_TAB_SECOND },
        { "seconds", IDS_BRAVE_NEW_TAB_SECONDS },
        { "minute", IDS_BRAVE_NEW_TAB_MINUTE },
        { "minutes", IDS_BRAVE_NEW_TAB_MINUTES },
        { "hour", IDS_BRAVE_NEW_TAB_HOUR },
        { "hours", IDS_BRAVE_NEW_TAB_HOURS },
        { "day", IDS_BRAVE_NEW_TAB_DAY },
        { "days", IDS_BRAVE_NEW_TAB_DAYS },
        { "privateNewTabTitle", IDS_BRAVE_PRIVATE_NEW_TAB_TITLE },
        { "privateNewTabDisclaimer1", IDS_BRAVE_PRIVATE_NEW_TAB_DISCLAIMER_1 },
        { "privateNewTabDisclaimer2", IDS_BRAVE_PRIVATE_NEW_TAB_DISCLAIMER_2 },
        { "duckduckGoSearchInfo", IDS_BRAVE_PRIVATE_NEW_TAB_DUCKDUCKGO_SEARCH_INFO },
        { "privateNewTabSearchLabel", IDS_BRAVE_PRIVATE_NEW_TAB_SEARCH_TOGGLE_LABEL }
      }
    }, {
      std::string("welcome"), {
      }
    }, {
      std::string("rewards"), {
      }
    }, {
      std::string("adblock"), {
        { "adsBlocked", IDS_ADBLOCK_TOTAL_ADS_BLOCKED },
        { "regionalAdblockEnabledTitle", IDS_ADBLOCK_REGIONAL_AD_BLOCK_ENABLED_TITLE},
        { "regionalAdblockEnabled", IDS_ADBLOCK_REGIONAL_AD_BLOCK_ENABLED },
        { "regionalAdblockDisabled", IDS_ADBLOCK_REGIONAL_AD_BLOCK_DISABLED },
      }
    }
  };
  AddLocalizedStringsBulk(source, localized_strings[name]);
}
